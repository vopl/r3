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
			mutex::scoped_lock sl(_fiberPool->_mtxFibers);
			_fiberPool->_fibersIdle.insert(fiber->shared_from_this());
			assert(
				_fiberPool->_fibersReady.end() == 
				std::find(_fiberPool->_fibersReady.begin(), _fiberPool->_fibersReady.end(), fiber->shared_from_this()));
		}
		bool b = _fiberRoot->activate();
		assert(b);
	}

	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::fiberReady(FiberImplPtr fiber)
	{
		mutex::scoped_lock sl(_fiberPool->_mtxFibers);
		assert(fiber != _fiberRoot);
		//assert(fiber.get() != FiberImpl::current());
		assert(_fiberPool->_fibersIdle.end() == _fiberPool->_fibersIdle.find(fiber));
		_fiberPool->_fibersReady.push_back(fiber);
	}

	//////////////////////////////////////////////////////////////////////////
	bool WorkerImpl::fiberReadyIfWait(FiberImplPtr fiber)
	{
		mutex::scoped_lock sl(_fiberPool->_mtxFibers);
		assert(fiber != _fiberRoot);
		assert(fiber.get() != FiberImpl::current());

		if(_fiberPool->_fibersIdle.end() != _fiberPool->_fibersIdle.find(fiber))
		{
			return false;
		}
		_fiberPool->_fibersReady.push_back(fiber);
		return true;
	}

	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::fiberYield()
	{
		assert(FiberImpl::current() != _fiberRoot.get());
		bool b = _fiberRoot->activate();
		assert(b);
	}


	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::processReadyFibers()
	{
		bool doWork = true;
		while(doWork)
		{
			std::deque<FiberImplPtr> fibersReady;
			{
				mutex::scoped_lock sl(_fiberPool->_mtxFibers);
				fibersReady.swap(_fiberPool->_fibersReady);
			}

			size_t activatedAmount = 0;
			BOOST_FOREACH(const FiberImplPtr &fiber, fibersReady)
			{
				if(fiber->activate())
				{
					activatedAmount++;
				}
				else
				{
					mutex::scoped_lock sl(_fiberPool->_mtxFibers);
					_fiberPool->_fibersReady.push_back(fiber);
				}
			}

			doWork = activatedAmount?true:false;
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
		std::set<FiberImplPtr>	fibersNotActavated;
		for(;;)
		{
			FiberImplPtr fiber;
			TTask tasksFromQueue;

			//////////////////////////////////////////////////////////////////////////
			{
				mutex::scoped_lock sl(_fiberPool->_mtxTasks);
				if(!_fiberPool->_tasks.empty())
				{
					tasksFromQueue.swap(*_fiberPool->_tasks.begin());
					_fiberPool->_tasks.erase(_fiberPool->_tasks.begin());
				}
			}
			{
				mutex::scoped_lock sl(_fiberPool->_mtxFibers);
				if(!_fiberPool->_fibersIdle.empty())
				{
					fiber.swap((FiberImplPtr &)*_fiberPool->_fibersIdle.begin());
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
					if(!fiber->execute(tasksFromQueue))
					{
						fibersNotActavated.insert(fiber);
						continue;
					}
				}
				else
				{
					if(!fiber->execute(task))
					{
						fibersNotActavated.insert(fiber);
						continue;
					}
					break;
				}
			}
			else
			{
				mutex::scoped_lock sl(_fiberPool->_mtxTasks);
				if(tasksFromQueue)
				{
					_fiberPool->_tasks.push_front(tasksFromQueue);
				}
				_fiberPool->_tasks.push_back(task);
				break;
			}
		}

		if(!fibersNotActavated.empty())
		{
			mutex::scoped_lock sl(_fiberPool->_mtxFibers);
			_fiberPool->_fibersIdle.insert(fibersNotActavated.begin(), fibersNotActavated.end());
		}

		//теперь снова готовые
		processReadyFibers();
	}

	//////////////////////////////////////////////////////////////////////////
	void WorkerImpl::yield()
	{
		assert(FiberImpl::current());

		FiberImplPtr fiber = FiberImpl::current()->shared_from_this();
		if(fiber == _fiberRoot)
		{
			assert(!"root fiber unable to yield");
			return;
		}

		service()->io().post(bridge(bind(&WorkerImpl::fiberReady, shared_from_this(), fiber)));
		fiberYield();
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
