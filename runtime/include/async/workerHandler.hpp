#ifndef _ASYNC_WORKERHANDLER_HPP_
#define _ASYNC_WORKERHANDLER_HPP_

#include "async/worker.hpp"

namespace async
{
}

namespace boost
{
	namespace asio
	{
		template <typename Function, typename Any>
		inline void asio_handler_invoke(Function &function, Any stub)
		{
			async::Worker::current()->doComplete(function);
		}
	}
}


#endif
