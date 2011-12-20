#ifndef _ASYNC_SERVICEWORKER_HPP_
#define _ASYNC_SERVICEWORKER_HPP_

#include <boost/thread.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "async/worker.hpp"
#include "fiberImpl.hpp"
#include "fiberRootImpl.hpp"
#include <set>
#include <deque>

#include "fiberPool.hpp"

namespace async
{
	class Service;
	typedef boost::shared_ptr<Service> ServicePtr;

	//////////////////////////////////////////////////////////////////////////
	class WorkerImpl
		: public Worker
		, public boost::enable_shared_from_this<WorkerImpl>
	{
		ServicePtr		_service;
		boost::thread	_thread;
		volatile bool	_stop;

	private:
		typedef boost::function<void()> TTask;

		//головной фибер, в нем исполняется цикл выкачивания событий проактора
		FiberRootImplPtr	_fiberRoot;

		FiberPoolPtr		_fiberPool;

		static ThreadLocalStorage<WorkerImpl *> _current;

	private:
		void threadProc();

	public://для фиберов
		void fiberExecuted(FiberImpl *fiber);
		void fiberReady(FiberImpl *fiber);
		void fiberYield(FiberImpl *fiber);

	private:
		void processReadyFibers();
	public://для врапера
		void doComplete(TTask);

	public:
		WorkerImpl(ServicePtr service, FiberPoolPtr	fiberPool);
		~WorkerImpl();

		static WorkerImpl *current();
	};
	typedef boost::shared_ptr<WorkerImpl> WorkerImplPtr;
}

#endif
