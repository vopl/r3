#ifndef _ASYNC_SERVICEWORKER_HPP_
#define _ASYNC_SERVICEWORKER_HPP_

#include <boost/thread.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "fiberImpl.hpp"
#include "fiberRootImpl.hpp"
#include <set>
#include <deque>

#include "fiberPool.hpp"

namespace async
{
	class ServiceImpl;
	typedef shared_ptr<ServiceImpl> ServiceImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class WorkerImpl
		: public enable_shared_from_this<WorkerImpl>
	{
		ServiceImplPtr	_service;
		thread			_thread;
		volatile bool	_stop;

	private:
		typedef function<void()> TTask;

		//головной фибер, в нем исполняется цикл выкачивания событий проактора
		FiberRootImplPtr	_fiberRoot;

		//шареный буфер с фиберами, в нем простаивающие без кода и готовые к исполнению
		FiberPoolPtr		_fiberPool;

		static ThreadLocalStorage<WorkerImpl *>
							_current;

	private:
		void threadProc();

	private:
		void processReadyFibers();

	public://для фиберов

		//не умный потому что этот метод будет вызываться из рабочей процедуры фибера и она не должна делать RAII чтобы не унести с собой объект фибера при разрушении
		void fiberExecuted(FiberImpl *fiber);
		void fiberReady(FiberImplPtr fiber);
		bool fiberReadyIfWait(FiberImplPtr fiber);
		void fiberYield();

	public://для врапера asio
		void exec(const TTask &);
		void yield();

	public:
		WorkerImpl(ServiceImplPtr service, FiberPoolPtr	fiberPool);
		~WorkerImpl();

		const ServiceImplPtr &service();

		static WorkerImpl *current();
	};
	typedef shared_ptr<WorkerImpl> WorkerImplPtr;
}

#endif
