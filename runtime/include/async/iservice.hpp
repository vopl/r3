#ifndef _ASYNC_ISERVICE_HPP_
#define _ASYNC_ISERVICE_HPP_

#include "pluma/pluma.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/asio/io_service.hpp>

namespace async
{
	struct IService
	{
		virtual void start(
			size_t numThreads,
			boost::function<void ()> threadStart = boost::function<void ()>(),
			boost::function<void ()> threadStop = boost::function<void ()>()) =0;

		virtual void balance(size_t numThreads) =0;
		virtual void stop() =0;

		virtual boost::asio::io_service &get_io_service() =0;
	};
	PLUMA_PROVIDER_HEADER(IService);
	typedef boost::shared_ptr<IService> IServicePtr;
}
#endif
