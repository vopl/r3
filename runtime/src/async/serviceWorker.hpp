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

		//�������� �����, � ��� ����������� ���� ����������� ������� ���������
		FiberRoot		*_fiberRoot;

		//��� ������� ������
		std::deque<Fiber *> _fibers;

		//������� ������ ��� ������
		std::set<Fiber *> _fibersIdle;

		//������� ������ � ������� � ������� � ����������
		std::deque<Fiber *> _fibersReady;
		boost::mutex	_fibersReadyMtx;

	private:
		void threadProc();

	public://��� �������
		void fiberExecuted(Fiber *fiber);

	public:
		ServiceWorker(ServicePtr service);
		~ServiceWorker();

	};
	typedef boost::shared_ptr<ServiceWorker> ServiceWorkerPtr;
}

#endif
