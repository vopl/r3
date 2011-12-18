#ifndef _ASYNC_SERVICEWORKER_HPP_
#define _ASYNC_SERVICEWORKER_HPP_

#include <boost/thread.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "async/worker.hpp"
#include "fiberImpl.hpp"
#include "fiberRootImpl.hpp"
#include <set>
#include <deque>

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
		std::set<FiberImplPtr> _fibersIdle;

		//������� ������ � ������� � ������� � ����������
		std::deque<FiberImplPtr> _fibersReady;
		//boost::mutex	_fibersReadyMtx;

		static ThreadLocalStorage<WorkerImpl *> _current;

	private:
		void threadProc();

	public://��� �������
		void fiberExecuted(FiberImplPtr fiber);
		void fiberReady(FiberImplPtr fiber);
		void fiberYield(FiberImplPtr fiber);

	public://��� �������
		void doComplete(TTask);

	public:
		WorkerImpl(ServicePtr service);
		~WorkerImpl();

		static WorkerImpl *current();
	};
	typedef boost::shared_ptr<WorkerImpl> WorkerImplPtr;
}

#endif
