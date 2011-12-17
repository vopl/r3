#include "pch.h"
#include "serviceWorker.hpp"
#include "service.hpp"
#include <boost/bind.hpp>

namespace async
{
#define FIBERS_ON_THREAD 10

	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<ServiceWorker *> ServiceWorker::_current;

	//////////////////////////////////////////////////////////////////////////
	void ServiceWorker::threadProc()
	{
		_current = this;

		current();
		if(_service->_threadStart)
		{
			_service->_threadStart();
		}

		//наболтать головной фибер
		_fiberRoot.reset(new FiberRoot(this));

		while(!_stop)
		{
			boost::system::error_code ec;
			size_t events = _service->_io_service.run(ec);
		}


		if(_service->_threadStop)
		{
			_service->_threadStop();
		}

		assert(_fibersReady.empty());
		_fiberRoot.reset();
		_current = NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceWorker::fiberExecuted(FiberPtr fiber)
	{
		_fiberRoot->activate();
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ServiceWorker::fiberReady(Fiber *fiber)
	{
		mutex::scoped_lock sl(_fibersReadyMtx);
		_fibersReady.insert(fiber->shared_from_this());
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ServiceWorker::fiberYield(Fiber *fiber)
	{
		_fiberRoot->activate();
	}


	//////////////////////////////////////////////////////////////////////////
	void ServiceWorker::ready(TTask task)
	{
		//сначала отработать все готовые
		bool doWork = true;
		while(doWork)
		{
			std::deque<FiberPtr> fibersReady;
			{
				boost::mutex::scoped_lock sl(_fibersReadyMtx);
				fibersReady.swap(_fibersReady);
			}

			doWork = !fibersReady.empty();
			BOOST_FOREACH(FiberPtr &fiber, fibersReady)
			{
				fiber->activate();
			}
		}

		//потом входящую задачу
		FiberPtr fiber(new Fiber(this));
		fiber->execute(task);
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceWorker::ServiceWorker(ServicePtr service)
		: _service(service)
		, _stop(false)
		, _fiberRoot()
	{
		_thread = boost::thread(boost::bind(&ServiceWorker::threadProc, this));
	}
	
	//////////////////////////////////////////////////////////////////////////
	ServiceWorker::~ServiceWorker()
	{
		_stop = true;
		_thread.join();

		assert(!_fiberRoot);
		assert(_fibersReady.empty());
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceWorker *ServiceWorker::current()
	{
		return _current;
	}

}
