#ifndef _ASYNC_SERVICE_HPP_
#define _ASYNC_SERVICE_HPP_

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>

namespace async
{
	class ServiceImpl;
	class Service
	{
	protected:
		typedef boost::shared_ptr<ServiceImpl> ImplPtr;
		ImplPtr _impl;

	public:
		Service();

		void start(
			size_t numThreads,
			boost::function<void ()> threadStart = boost::function<void ()>(),
			boost::function<void ()> threadStop = boost::function<void ()>());

		void balance(size_t numThreads);
		void stop();

		boost::asio::io_service &get_io_service();
	};
}
#endif
