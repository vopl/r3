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

		//�������� �����, � ��� ����������� ���� ����������� ������� ���������
		FiberRootImplPtr	_fiberRoot;

		FiberPoolPtr		_fiberPool;

		static ThreadLocalStorage<WorkerImpl *> _current;

	private:
		void threadProc();

	public://��� �������
		void fiberExecuted(FiberImpl *fiber);
		void fiberReady(FiberImpl *fiber);
		void fiberYield(FiberImpl *fiber);

	private:
		void processReadyFibers();
	public://��� �������
		void doComplete(TTask);

	public:
		WorkerImpl(ServicePtr service, FiberPoolPtr	fiberPool);
		~WorkerImpl();

		static WorkerImpl *current();
	};
	typedef boost::shared_ptr<WorkerImpl> WorkerImplPtr;
}

#endif
