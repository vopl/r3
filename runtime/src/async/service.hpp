#ifndef _ASYNC_SERVICE_HPP_
#define _ASYNC_SERVICE_HPP_

#include "async/iservice.hpp"
#include <boost/enable_shared_from_this.hpp>

#include "serviceWorker.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	class Service
		: public IService
		, public boost::enable_shared_from_this<Service>
	{
		friend class ServiceWorker;
		boost::asio::io_service			_io_service;
		boost::shared_ptr<boost::asio::io_service::work>	_work;

		std::vector<ServiceWorkerPtr>	_workers;

		boost::function<void ()> _threadStart;
		boost::function<void ()> _threadStop;

	public:
		Service();
		~Service();

		virtual void start(
			size_t numThreads,
			boost::function<void ()> threadStart,
			boost::function<void ()> threadStop);

		virtual void balance(size_t numThreads);
		virtual void stop();

		virtual void dispatch(boost::function<void()> handler);

		virtual boost::asio::io_service &get_io_service();
	};
	PLUMA_INHERIT_PROVIDER(Service, IService);
}
#endif
