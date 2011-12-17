#include "pch.h"
#include "serviceWorker.hpp"
#include "service.hpp"
#include <boost/bind.hpp>

namespace async
{
#define FIBERS_ON_THREAD 10
	//////////////////////////////////////////////////////////////////////////
	void ServiceWorker::threadProc()
	{
		if(_service->_threadStart)
		{
			_service->_threadStart();
		}

		//наболтать фиберов
		_fiberRoot = new FiberRoot(this);
		for(size_t i(0); i<FIBERS_ON_THREAD; i++)
		{
			_fibers.push_back(new Fiber(this));
			_fibersIdle.insert(_fibers.back());
		}

		while(!_stop)
		{
			boost::system::error_code ec;
			size_t events = _service->_io_service.poll_one(ec);
			if(!events)
			{
				boost::xtime xt;
				boost::xtime_get(&xt, boost::TIME_UTC);
				xt.nsec += 1000000;
				boost::thread::sleep(xt);
			}

			bool doWork = true;

			while(doWork)
			{
				doWork = !_tasks.empty() && !_fibersIdle.empty();

				while(!_tasks.empty() && !_fibersIdle.empty())
				{
					//взять пустой фибер из пула, отдать ему задачу
					TTask task = _tasks.front();
					_tasks.pop_front();

					Fiber *fiber = *_fibersIdle.begin();
					_fibersIdle.erase(_fibersIdle.begin());

					fiber->execute(task);
				}

				std::deque<Fiber *> fibersReady;
				{
					boost::mutex::scoped_lock sl(_fibersReadyMtx);
					fibersReady.swap(_fibersReady);
				}

				doWork |= !fibersReady.empty();
				BOOST_FOREACH(Fiber *fiber, fibersReady)
				{
					fiber->activate();
				}
			}
		}

		_fibersIdle.clear();

		delete _fiberRoot;
		_fiberRoot = NULL;

		BOOST_FOREACH(Fiber *fiber, _fibers)
		{
			delete fiber;
		}
		_fibers.clear();

		if(_service->_threadStop)
		{
			_service->_threadStop();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceWorker::fiberExecuted(Fiber *fiber)
	{
		assert(_fibers.end() != std::find(_fibers.begin(), _fibers.end(), fiber));
		assert(_fibersIdle.end() == _fibersIdle.find(fiber));
		_fibersIdle.insert(fiber);
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceWorker::ServiceWorker(ServicePtr service)
		: _service(service)
		, _stop(false)
		, _fiberRoot(NULL)
	{
		_thread = boost::thread(boost::bind(&ServiceWorker::threadProc, this));
	}
	
	//////////////////////////////////////////////////////////////////////////
	ServiceWorker::~ServiceWorker()
	{
		_stop = true;
		_thread.join();

		assert(_tasks.empty());
		assert(!_fiberRoot);
		assert(_fibers.empty());
		assert(_fibersIdle.empty());
		assert(_fibersReady.empty());
	}

}
