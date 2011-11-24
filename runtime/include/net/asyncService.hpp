#ifndef _NET_ASYNCSERVICE_HPP_
#define _NET_ASYNCSERVICE_HPP_

#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

namespace net
{
	class AsyncServiceImpl;
	class AsyncService
	{
	protected:
		typedef boost::shared_ptr<AsyncServiceImpl> ImplPtr;
		ImplPtr _impl;

	public:
		AsyncService();

		void start(
			size_t numThreads,
			boost::function<void ()> threadStart = boost::function<void ()>(),
			boost::function<void ()> threadStop = boost::function<void ()>());

		void balance(size_t numThreads);
		void stop();
	};
}
#endif
