#ifndef _ASYNC_WORKERHANDLER_HPP_
#define _ASYNC_WORKERHANDLER_HPP_

#include "async/iservice.hpp"

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


		WorkerHandler(IServicePtr asrv, const Handler& handler)
			: _handler(handler)
			, _asrv(asrv)
		{
		}



		~WorkerHandler()
		{
		}

		void operator()()
		{
			_asrv->dispatch(_handler);
		}    

		template <typename Arg1>
		void operator()(const Arg1& arg1)
		{
			_asrv->dispatch(boost::bind(_handler, arg1));
		}

		template <typename Arg1, typename Arg2>
		void operator()(const Arg1& arg1, const Arg2& arg2)
		{
			_asrv->dispatch(boost::bind(_handler, arg1, arg2));
		}

		template <typename Arg1, typename Arg2, typename Arg3>
		void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3)
		{
			_asrv->dispatch(boost::bind(_handler, arg1, arg2, arg3));
		}

		template <typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, 
			const Arg4& arg4)
		{
			_asrv->dispatch(boost::bind(_handler, arg1, arg2, arg3, arg4));
		}

		template <typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
			typename Arg5>
			void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, 
			const Arg4& arg4, const Arg5& arg5)
		{
			_asrv->dispatch(boost::bind(_handler, arg1, arg2, arg3, arg4, arg5));
		}  

		void operator()() const
		{
			_asrv->dispatch(_handler);
		}

		template <typename Arg1>
		void operator()(const Arg1& arg1) const
		{
			_asrv->dispatch(boost::bind(_handler, arg1));
		}

		template <typename Arg1, typename Arg2>
		void operator()(const Arg1& arg1, const Arg2& arg2) const
		{
			_asrv->dispatch(boost::bind(_handler, arg1, arg2));
		}

		template <typename Arg1, typename Arg2, typename Arg3>
		void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3) const
		{
			_asrv->dispatch(boost::bind(_handler, arg1, arg2, arg3));
		}

		template <typename Arg1, typename Arg2, typename Arg3, typename Arg4>
		void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, 
			const Arg4& arg4) const
		{
			_asrv->dispatch(boost::bind(_handler, arg1, arg2, arg3, arg4));
		}

		template <typename Arg1, typename Arg2, typename Arg3, typename Arg4, 
			typename Arg5>
			void operator()(const Arg1& arg1, const Arg2& arg2, const Arg3& arg3, 
			const Arg4& arg4, const Arg5& arg5) const
		{
			_asrv->dispatch(boost::bind(_handler, arg1, arg2, arg3, arg4, arg5));
		}

	private:

		IServicePtr _asrv;
		Handler _handler;
	}; //class WorkerHandler

	template <typename Handler>
	inline WorkerHandler<Handler> 
		wrapWorkerHandler(IServicePtr asrv, const Handler& handler)
	{
		return WorkerHandler<Handler>(asrv, handler);
	}
}

#endif
