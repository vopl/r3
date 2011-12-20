#include "pch.h"
#include "serviceImpl.hpp"
#include <boost/foreach.hpp>

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<ServiceImpl *> ServiceImpl::_current;

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

			_threadStart.swap(function<void ()>());
			_threadStop.swap(function<void ()>());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::spawn(const boost::function<void ()> &code)
	{
		_io.post(code);
	}
	

	//////////////////////////////////////////////////////////////////////////
	asio::io_service &ServiceImpl::io()
	{
		return _io;
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceImpl *ServiceImpl::current()
	{
		return _current;
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
