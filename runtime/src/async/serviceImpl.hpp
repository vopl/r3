#ifndef _ASYNC_SERVICEIMPL_HPP_
#define _ASYNC_SERVICEIMPL_HPP_

#include "async/service.hpp"
#include <boost/enable_shared_from_this.hpp>

#include "workerImpl.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	class ServiceImpl
		: public Service
		, public boost::enable_shared_from_this<ServiceImpl>
	{
		friend class WorkerImpl;
		boost::asio::io_service			_io_service;
		boost::shared_ptr<boost::asio::io_service::work>	_work;

		std::vector<WorkerImplPtr>	_workers;
		FiberPoolPtr				_fiberPool;

		boost::function<void ()> _threadStart;
		boost::function<void ()> _threadStop;

	public:
		ServiceImpl();
		~ServiceImpl();

		virtual void start(
			size_t numThreads,
			const boost::function<void ()> &threadStart,
			const boost::function<void ()> &threadStop);

		virtual void balance(size_t numThreads);
		virtual void stop();
	};
}
#endif
