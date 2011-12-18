#ifndef _ASYNC_WORKERHANDLER_HPP_
#define _ASYNC_WORKERHANDLER_HPP_

#include "async/worker.hpp"

namespace async
{

	//////////////////////////////////////////////////////////////////////////
	template <typename Handler>
	class WorkerHandler
	{
	private:
		typedef WorkerHandler<Handler> this_type;
		this_type& operator=(const this_type&);

	public:
		typedef void result_type;


		WorkerHandler(const Handler& handler)
			: _handler(handler)
		{
		}



		~WorkerHandler()
		{
		}

		void operator()()
		{
			Worker::current()->doComplete(_handler);
		}    

		template <typename Arg1>
		void operator()(const Arg1& arg1)
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1));
		}

		template <typename Arg1, typename Arg2>
		void operator()(const Arg1& arg1, const Arg2& arg2)
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1, arg2));
		}

		template <typename Arg1, typename Arg2, typename Arg3>
		void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3)
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1, arg2, arg3));
		}

		template <typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, 
			const Arg4& arg4)
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1, arg2, arg3, arg4));
		}

		template <typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
			typename Arg5>
			void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, 
			const Arg4& arg4, const Arg5& arg5)
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1, arg2, arg3, arg4, arg5));
		}  

		void operator()() const
		{
			Worker::current()->doComplete(_handler);
		}

		template <typename Arg1>
		void operator()(const Arg1& arg1) const
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1));
		}

		template <typename Arg1, typename Arg2>
		void operator()(const Arg1& arg1, const Arg2& arg2) const
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1, arg2));
		}

		template <typename Arg1, typename Arg2, typename Arg3>
		void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3) const
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1, arg2, arg3));
		}

		template <typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, 
			const Arg4& arg4) const
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1, arg2, arg3, arg4));
		}

		template <typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
			typename Arg5>
			void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, 
			const Arg4& arg4, const Arg5& arg5) const
		{
			Worker::current()->doComplete(boost::bind(_handler, arg1, arg2, arg3, arg4, arg5));
		}

	private:

		Handler _handler;
	}; //class WorkerHandler


	template <class Handler>
	WorkerHandler<Handler> makeWorkerHandler(const Handler& handler)
	{
		return WorkerHandler<Handler>(handler);
	}
	
}


#endif
