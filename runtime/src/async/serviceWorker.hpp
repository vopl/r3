#ifndef _ASYNC_SERVICEWORKER_HPP_
#define _ASYNC_SERVICEWORKER_HPP_

#include <boost/thread.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "fiber.hpp"
#include "fiberRoot.hpp"
#include <set>
#include <deque>

namespace async
{
	class Service;
	typedef boost::shared_ptr<Service> ServicePtr;

	//////////////////////////////////////////////////////////////////////////
	class ServiceWorker
		: public boost::enable_shared_from_this<ServiceWorker>
	{
		ServicePtr		_service;
		boost::thread	_thread;
		volatile bool	_stop;

	private:
		typedef boost::function<void()> TTask;

		//головной фибер, в нем исполняется цикл выкачивания событий проактора
		FiberRootPtr	_fiberRoot;

		//рабочие фиберы с задачей и готовые к исполнению
		std::deque<FiberPtr> _fibersReady;
		boost::mutex	_fibersReadyMtx;

		static ThreadLocalStorage<ServiceWorker *> _current;

	private:
		void threadProc();

	public://для фиберов
		void fiberExecuted(Fiber *fiber);
		void fiberReady(Fiber *fiber);
		void fiberYield(Fiber *fiber);

	public://для врапера
		void ready(TTask);

	public:
		ServiceWorker(ServicePtr service);
		~ServiceWorker();

		static ServiceWorker *current();
	};
	typedef boost::shared_ptr<ServiceWorker> ServiceWorkerPtr;
}

#endif
