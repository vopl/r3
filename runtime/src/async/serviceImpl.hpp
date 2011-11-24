#ifndef _ASYNC_SERVICEIMPL_HPP_
#define _ASYNC_SERVICEIMPL_HPP_

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	class ServiceImpl
		: public boost::enable_shared_from_this<ServiceImpl>
	{
		boost::asio::io_service			_io_service;
		boost::shared_ptr<boost::asio::io_service::work>	_work;

		struct ServiceWorker
		{
			boost::thread		_thread;
			volatile bool		_stop;
		};
		typedef boost::shared_ptr<ServiceWorker> ServiceWorkerPtr;
		void workerProc(ServiceWorkerPtr swp);

		std::vector<ServiceWorkerPtr>	_workers;

		boost::function<void ()> _threadStart;
		boost::function<void ()> _threadStop;

		boost::mutex _mtx;

	public:
		ServiceImpl();
		~ServiceImpl();

		void start(
			size_t numThreads,
			boost::function<void ()> threadStart,
			boost::function<void ()> threadStop);

		void balance(size_t numThreads);
		void stop();

		boost::asio::io_service &get_io_service();
	};
	typedef boost::shared_ptr<ServiceImpl> ServiceImplPtr;
}
#endif
