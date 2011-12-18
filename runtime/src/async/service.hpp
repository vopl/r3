#ifndef _ASYNC_SERVICE_HPP_
#define _ASYNC_SERVICE_HPP_

#include "async/iservice.hpp"
#include <boost/enable_shared_from_this.hpp>

#include "workerImpl.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	class ASYNC_API Service
		: public IService
		, public boost::enable_shared_from_this<Service>
	{
		friend class WorkerImpl;
		boost::asio::io_service			_io_service;
		boost::shared_ptr<boost::asio::io_service::work>	_work;

		std::vector<WorkerImplPtr>	_workers;

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

		virtual boost::asio::io_service &get_io_service();
	};
}
#endif
