#ifndef _ASYNC_WORKER_HPP_
#define _ASYNC_WORKER_HPP_

#include "async/api.h"
#include <boost/shared_ptr.hpp>


//////////////////////////////////////////////////////////////////////////
namespace async
{
	//////////////////////////////////////////////////////////////////////////
	template <typename Handler> class WorkerHandler;

	//////////////////////////////////////////////////////////////////////////
	class ASYNC_API Worker
	{
	protected:
		Worker();
		Worker(const Worker&);

	private:
		template <typename Handler> friend class WorkerHandler;
		void doComplete(boost::function<void()> handler);

	public:
		virtual ~Worker();

		static Worker *current();

		template <class Handler>
		static WorkerHandler<Handler> wrap(const Handler &handler);
	};
}

#include "workerHandler.hpp"

namespace async
{
	template <class Handler>
	WorkerHandler<Handler> Worker::wrap(const Handler& handler)
	{
		return WorkerHandler<Handler>(handler);
	}

}



#endif
