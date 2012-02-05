#include "pch.h"
#include "serviceImpl.hpp"
#include <boost/foreach.hpp>

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<ServiceImpl *> ServiceImpl::_current;

	ServiceImpl *ServiceImpl::_global = NULL;

	//////////////////////////////////////////////////////////////////////////
	ServiceImpl::ServiceImpl()
		: _io()
		, _work()
		, _threadStart()
		, _threadStop()
		, _fiberPool(new FiberPool)
	{
		ILOG("create");
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceImpl::~ServiceImpl()
	{
		ILOG("detroy");
		//stop();
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::start(
		size_t numThreads,
		const function<void ()> &threadStart,
		const function<void ()> &threadStop)
	{
		ILOG("start");
		{
			mutex::scoped_lock sl(_mtx);
			assert(!_threadStart);
			_threadStart = threadStart;
			_threadStop = threadStop;
		}
		balance(numThreads);
		ILOG("start done");
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::balance(size_t numThreads)
	{
		ILOG("balance "<<numThreads);

		std::vector<WorkerImplPtr>	stopped;
		{
			mutex::scoped_lock sl(_mtx);

			while(_workers.size() > numThreads)
			{
				stopped.push_back(_workers.back());
				_workers.pop_back();

			}
			while(_workers.size() < numThreads)
			{
				WorkerImplPtr swp(new WorkerImpl(shared_from_this(), _fiberPool));
				_workers.push_back(swp);
			}
		}

		if(!stopped.empty())
		{
			_work.reset();
			BOOST_FOREACH(WorkerImplPtr &swp, stopped)
			{
				swp.reset();
			}
		}

		if(!_workers.empty())
		{
			_work.reset(new asio::io_service::work(_io));
		}

		ILOG("balance done");
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::stop()
	{
		ILOG("stop");
		balance(0);

		{
			mutex::scoped_lock sl(_mtx);

			function<void ()>().swap(_threadStart);
			function<void ()>().swap(_threadStop);
		}
		ILOG("stop done");
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::spawn(const boost::function<void ()> &code)
	{
		{
			mutex::scoped_lock sl(_fiberPool->_mtxTasks);
			if(!_fiberPool->_tasks.empty())
			{
				//исполнение уже идет, воркер будет выгребать все задачи, подсунуть ему еще и эту
				_fiberPool->_tasks.push_back(code);
				return;
			}
		}

		//небыло задач к исполнителю, надо инициировать воркера
		_io.post(bridge(code));
	}


	//////////////////////////////////////////////////////////////////////////
	asio::io_service &ServiceImpl::io()
	{
		return _io;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ServiceImpl::setAsGlobal(bool force)
	{
		if(_global && !force)
		{
			return false;
		}
		_global = this;
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceImpl *ServiceImpl::current()
	{
		ServiceImpl *res = _current;
		if(!res)
		{
			res = _global;
		}
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::onThreadStart()
	{
		_current = this;
		{
			mutex::scoped_lock sl(_mtx);
			if(_threadStart)
			{
				_threadStart();
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::onThreadStop()
	{
		{
			mutex::scoped_lock sl(_mtx);
			if(_threadStop)
			{
				_threadStop();
			}
		}
		_current = NULL;
	}

}
