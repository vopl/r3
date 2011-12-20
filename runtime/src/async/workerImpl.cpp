#include "pch.h"
#include "workerImpl.hpp"
#include "serviceImpl.hpp"
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
		_fiberRoot->initialize();

		_service->onThreadStart();

		while(!_stop)
		{
			system::error_code ec;
			try
			{
				_service->io().run(ec);
			}
			catch(...)
			{
				ELOG(__FUNCTION__<<", exception catched: "<<boost::current_exception_diagnostic_information());
			}

		}

		_service->onThreadStop();

		_fiberRoot.reset();
		_current = NULL;
	}

	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::fiberExecuted(FiberImpl *fiber)
	{
		assert(fiber != _fiberRoot.get());
		assert(fiber == FiberImpl::current());
		{
			mutex::scoped_lock sl(_fiberPool->_mtx);
			_fiberPool->_fibersIdle.insert(fiber->shared_from_this());
			assert(_fiberPool->_fibersReady.end() == _fiberPool->_fibersReady.find(fiber->shared_from_this()));
		}
		_fiberRoot->activate();
	}

	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::fiberReady(FiberImplPtr fiber)
	{
		mutex::scoped_lock sl(_fiberPool->_mtx);
		assert(fiber != _fiberRoot);
		assert(fiber.get() != FiberImpl::current());
		assert(_fiberPool->_fibersIdle.end() == _fiberPool->_fibersIdle.find(fiber));
		_fiberPool->_fibersReady.insert(fiber);
	}
	
	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::fiberYield()
	{
		assert(FiberImpl::current() != _fiberRoot.get());
		_fiberRoot->activate();
	}


	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::processReadyFibers()
	{
		bool doWork = true;
		while(doWork)
		{
			std::set<FiberImplPtr> fibersReady;
			{
				mutex::scoped_lock sl(_fiberPool->_mtx);
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
	void WorkerImpl::exec(const TTask &task)
	{
		//assert(FiberImpl::current() == _fiberRoot.get());
		if(FiberImpl::current() != _fiberRoot.get())
		{
			task();
			return;
		}
		assert(FiberImpl::current() == _fiberRoot.get());

		//сначала отработать все готовые
		processReadyFibers();

		//потом отложенные задачи
		//потом входящую задачу
		for(;;)
		{
			FiberImplPtr fiber;
			TTask tasksFromQueue;

			//////////////////////////////////////////////////////////////////////////
			{
				mutex::scoped_lock sl(_fiberPool->_mtx);

				if(!_fiberPool->_tasks.empty())
				{
					tasksFromQueue.swap(*_fiberPool->_tasks.begin());
					_fiberPool->_tasks.erase(_fiberPool->_tasks.begin());
				}

				if(!_fiberPool->_fibersIdle.empty())
				{
					fiber.swap(*_fiberPool->_fibersIdle.begin());
					_fiberPool->_fibersIdle.erase(_fiberPool->_fibersIdle.begin());
				}
			}

			//////////////////////////////////////////////////////////////////////////
			if(!fiber)
			{
				try
				{
					fiber.reset(new FiberImpl());
					if(!fiber->initialize())
					{
						fiber.reset();
					}
				}
				catch(...)
				{
					fiber.reset();
				}
			}

			if(fiber)
			{
				if(tasksFromQueue)
				{
					fiber->execute(tasksFromQueue);
				}
				else
				{
					fiber->execute(task);
					break;
				}
			}
			else
			{
				mutex::scoped_lock sl(_fiberPool->_mtx);
				if(tasksFromQueue)
				{
					_fiberPool->_tasks.push_front(tasksFromQueue);
				}
				_fiberPool->_tasks.push_back(task);
				break;
			}
		}

		//теперь снова готовые
		processReadyFibers();
	}

	//////////////////////////////////////////////////////////////////////////
	WorkerImpl::WorkerImpl(ServiceImplPtr service, FiberPoolPtr	fiberPool)
		: _service(service)
		, _stop(false)
		, _fiberRoot()
		, _fiberPool(fiberPool)
	{
		_thread = thread(bind(&WorkerImpl::threadProc, this));
	}
	
	//////////////////////////////////////////////////////////////////////////
	WorkerImpl::~WorkerImpl()
	{
		_stop = true;
		_thread.join();

		assert(!_fiberRoot);
	}

	//////////////////////////////////////////////////////////////////////////
	const ServiceImplPtr &WorkerImpl::service()
	{
		return _service;
	}

	//////////////////////////////////////////////////////////////////////////
	WorkerImpl *WorkerImpl::current()
	{
		return _current;
	}

}
