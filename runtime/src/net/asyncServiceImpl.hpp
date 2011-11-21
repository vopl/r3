#ifndef _NET_ASYNCSERVICEIMPL_HPP_
#define _NET_ASYNCSERVICEIMPL_HPP_

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	class AsyncServiceImpl
		: public boost::enable_shared_from_this<AsyncServiceImpl>
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
		AsyncServiceImpl();
		~AsyncServiceImpl();

		void start(
			size_t numThreads,
			boost::function<void ()> threadStart,
			boost::function<void ()> threadStop);

		void balance(size_t numThreads);
		void stop();

	public:
		boost::asio::io_service &io_service();
	};
	typedef boost::shared_ptr<AsyncServiceImpl> AsyncServiceImplPtr;
}
#endif
