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
		typedef std::deque<TTask> TTasks;
		TTasks _tasks;

		//головной фибер, в нем исполняется цикл выкачивания событий проактора
		FiberRoot		*_fiberRoot;

		//все рабочие фиберы
		std::deque<Fiber *> _fibers;

		//рабочие фиберы без задачи
		std::set<Fiber *> _fibersIdle;

		//рабочие фиберы с задачей и готовые к исполнению
		std::deque<Fiber *> _fibersReady;
		boost::mutex	_fibersReadyMtx;

	private:
		void threadProc();

	public://для фиберов
		void fiberExecuted(Fiber *fiber);

	public:
		ServiceWorker(ServicePtr service);
		~ServiceWorker();

	};
	typedef boost::shared_ptr<ServiceWorker> ServiceWorkerPtr;
}

#endif
