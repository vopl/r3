#ifndef _ASYNC_SERVICE_HPP_
#define _ASYNC_SERVICE_HPP_

#include "async/iservice.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	class Service
		: public IService
		, public boost::enable_shared_from_this<Service>
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
		Service();
		~Service();

		virtual void start(
			size_t numThreads,
			boost::function<void ()> threadStart,
			boost::function<void ()> threadStop);

		virtual void balance(size_t numThreads);
		virtual void stop();

		virtual boost::asio::io_service &get_io_service();
	};
	PLUMA_INHERIT_PROVIDER(Service, IService);
}
#endif
