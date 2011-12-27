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
		, public enable_shared_from_this<ServiceImpl>
	{
		asio::io_service			_io;
		shared_ptr<asio::io_service::work>
									_work;

		std::vector<WorkerImplPtr>	_workers;
		FiberPoolPtr				_fiberPool;

		function<void ()>			_threadStart;
		function<void ()>			_threadStop;

		mutex						_mtx;

		static ThreadLocalStorage<ServiceImpl *>
									_current;
		static ServiceImpl			*_global;

	public:
		ServiceImpl();
		~ServiceImpl();

		void start(
			size_t numThreads,
			const function<void ()> &threadStart,
			const function<void ()> &threadStop);

		void balance(size_t numThreads);
		void stop();

	public:
		void onThreadStart();
		void onThreadStop();

	public:
		void spawn(const boost::function<void ()> &code);
		asio::io_service &io();
		bool setAsGlobal(bool force);
		static ServiceImpl *current();
	};
}
#endif
