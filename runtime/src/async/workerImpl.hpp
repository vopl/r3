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

		//�������� �����, � ��� ����������� ���� ����������� ������� ���������
		FiberRootImplPtr	_fiberRoot;

		//������� ����� � ��������, � ��� ������������� ��� ���� � ������� � ����������
		FiberPoolPtr		_fiberPool;

		static ThreadLocalStorage<WorkerImpl *>
							_current;

	private:
		void threadProc();

	private:
		void processReadyFibers();

	public://��� �������

		//�� ����� ������ ��� ���� ����� ����� ���������� �� ������� ��������� ������ � ��� �� ������ ������ RAII ����� �� ������ � ����� ������ ������ ��� ����������
		void fiberExecuted(FiberImpl *fiber);
		void fiberReady(FiberImplPtr fiber);
		bool fiberReadyIfWait(FiberImplPtr fiber);
		void fiberYield();

	public://��� ������� asio
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
