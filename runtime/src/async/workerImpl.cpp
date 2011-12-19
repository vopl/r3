#include "pch.h"
#include "workerImpl.hpp"
#include "service.hpp"
#include <boost/bind.hpp>

namespace async
{

	//////////////////////////////////////////////////////////////////////////
	ThreadLocalStorage<WorkerImpl *> WorkerImpl::_current;

	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::threadProc()
	{
		_current = this;

		//наболтать головной фибер
		_fiberRoot.reset(new FiberRootImpl());

		if(_service->_threadStart)
		{
			_service->_threadStart();
		}

		while(!_stop)
		{
			boost::system::error_code ec;
			size_t events = _service->_io_service.run(ec);
		}


		if(_service->_threadStop)
		{
			_service->_threadStop();
		}

		//assert(_fibersReady.empty());
		_fiberRoot.reset();
		_current = NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::fiberExecuted(FiberImplPtr fiber)
	{
		{
			boost::mutex::scoped_lock sl(_fiberPool->_mtx);
			_fiberPool->_fibersIdle.insert(fiber);
		}
		_fiberRoot->activate();
	}

	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::fiberReady(FiberImplPtr fiber)
	{
		boost::mutex::scoped_lock sl(_fiberPool->_mtx);
		assert(_fiberRoot != fiber);
		//assert(_fibersReady.end() == _fibersReady.find(fiber));
		_fiberPool->_fibersReady.insert(fiber);
	}
	
	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::fiberYield(FiberImplPtr fiber)
	{
		assert(fiber != _fiberRoot);
		if(fiber != _fiberRoot)
		{
			_fiberRoot->activate();
		}
	}


	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::processReadyFibers()
	{
		bool doWork = true;
		while(doWork)
		{
			std::set<FiberImplPtr> fibersReady;
			{
				boost::mutex::scoped_lock sl(_fiberPool->_mtx);
				fibersReady.swap(_fiberPool->_fibersReady);
			}

			doWork = !fibersReady.empty();
			BOOST_FOREACH(FiberImplPtr &fiber, fibersReady)
			{
				fiber->activate();
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::doComplete(TTask task)
	{
		//assert(FiberImpl::current() == _fiberRoot);
		if(FiberImpl::current() != _fiberRoot)
		{
			task();
			return;
		}
		assert(FiberImpl::current() == _fiberRoot);

		//сначала отработать все готовые
		processReadyFibers();

		//потом входящую задачу
		{
			FiberImplPtr fiber;
			{
				boost::mutex::scoped_lock sl(_fiberPool->_mtx);
				if(_fiberPool->_fibersIdle.size())
				{
					fiber = *_fiberPool->_fibersIdle.begin();
					_fiberPool->_fibersIdle.erase(_fiberPool->_fibersIdle.begin());
				}
			}
			if(!fiber)
			{
				fiber.reset(new FiberImpl());
			}
			fiber->execute(task);
		}


		//теперь снова готовые
		processReadyFibers();
	}

	//////////////////////////////////////////////////////////////////////////
	WorkerImpl::WorkerImpl(ServicePtr service, FiberPoolPtr	fiberPool)
		: _service(service)
		, _stop(false)
		, _fiberRoot()
		, _fiberPool(fiberPool)
	{
		_thread = boost::thread(boost::bind(&WorkerImpl::threadProc, this));
	}
	
	//////////////////////////////////////////////////////////////////////////
	WorkerImpl::~WorkerImpl()
	{
		_stop = true;
		_thread.join();

		assert(!_fiberRoot);
		//assert(_fibersReady.empty());
	}

	//////////////////////////////////////////////////////////////////////////
	WorkerImpl *WorkerImpl::current()
	{
		return _current;
	}

}
