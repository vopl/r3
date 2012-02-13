#include "pch.hpp"
#include "serviceImpl.hpp"
#include <boost/foreach.hpp>

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<ServiceImpl *> ServiceImpl::_current;

	ServiceImpl *ServiceImpl::_global = NULL;

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::onTimer(const TTimerPtr &timer, const boost::system::error_code &ec, Future<boost::system::error_code> res)
	{
		res(ec);

		mutex::scoped_lock sl(_mtxTimers);
		_timers.erase(timer);
	}


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
		else
		{
			cancelAllTimeouts();
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
				//РёСЃРїРѕР»РЅРµРЅРёРµ СѓР¶Рµ РёРґРµС‚, РІРѕСЂРєРµСЂ Р±СѓРґРµС‚ РІС‹РіСЂРµР±Р°С‚СЊ РІСЃРµ Р·Р°РґР°С‡Рё, РїРѕРґСЃСѓРЅСѓС‚СЊ РµРјСѓ РµС‰Рµ Рё СЌС‚Сѓ
				_fiberPool->_tasks.push_back(code);
				return;
			}
		}

		//РЅРµР±С‹Р»Рѕ Р·Р°РґР°С‡ Рє РёСЃРїРѕР»РЅРёС‚РµР»СЋ, РЅР°РґРѕ РёРЅРёС†РёРёСЂРѕРІР°С‚СЊ РІРѕСЂРєРµСЂР°
		_io.post(bridge(code));
	}

	//////////////////////////////////////////////////////////////////////////
	Future<boost::system::error_code> ServiceImpl::timeout(size_t millisec)
	{
		Future<boost::system::error_code> res;
		mutex::scoped_lock sl(_mtxTimers);
		TTimerPtr timer(new asio::deadline_timer(_io, posix_time::milliseconds(millisec)));
		_timers.insert(timer);
		timer->async_wait(bridge(bind(&ServiceImpl::onTimer, shared_from_this(), timer, _1, res)));

		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::cancelAllTimeouts()
	{
		mutex::scoped_lock sl(_mtxTimers);
		BOOST_FOREACH(const TTimerPtr &timer, _timers)
		{
			timer->cancel();
		}
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
