#include "pch.h"
#include "serviceImpl.hpp"
#include <boost/foreach.hpp>

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	ServiceImpl::ServiceImpl()
		: _io_service()
		, _work()
		, _threadStart()
		, _threadStop()
		, _fiberPool(new FiberPool)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceImpl::~ServiceImpl()
	{
		//stop();
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::start(
		size_t numThreads,
		const boost::function<void ()> &threadStart,
		const boost::function<void ()> &threadStop)
	{
		ILOG("start");
		{
			//boost::mutex::scoped_lock sl(_mtx);
			assert(!_threadStart);
			_threadStart = threadStart;
			_threadStop = threadStop;
		}
		balance(numThreads);
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::balance(size_t numThreads)
	{
		ILOG("balance "<<numThreads);

		std::vector<WorkerImplPtr>	stopped;
		{
			//boost::mutex::scoped_lock sl(_mtx);

			while(_workers.size() > numThreads)
			{
				stopped.push_back(_workers.back());
				_workers.pop_back();

			}
			while(_workers.size() < numThreads)
			{
				WorkerImplPtr swp(new WorkerImpl(shared_from_this(), _fiberPool));
				_workers.push_back(swp);
			}

			if(!stopped.empty())
			{
				_work.reset();
				BOOST_FOREACH(WorkerImplPtr &swp, stopped)
				{
					swp.reset();
				}
			}

			if(!_workers.empty())
			{
				_work.reset(new boost::asio::io_service::work(_io_service));
			}
		}

		ILOG("balance done");
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceImpl::stop()
	{
		ILOG("stop");
		balance(0);
		_threadStart.swap(boost::function<void ()>());
		_threadStop.swap(boost::function<void ()>());
	}
}
