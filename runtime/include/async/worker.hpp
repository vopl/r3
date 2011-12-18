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

	public:
		//принимает исполнение завершенной операции asio
		//от asio_handler_invoke
		void doComplete(boost::function<void()> handler);

	public:
		virtual ~Worker();

		//получить экземпл€р текущего воркера
		static Worker *current();
	};
}

#include "workerHandler.hpp"


#endif
