#include "pch.h"
#include "service.hpp"
#include <boost/foreach.hpp>

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	Service::Service()
		: _io_service()
		, _work()
		, _threadStart()
		, _threadStop()
		, _fiberPool(new FiberPool)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Service::~Service()
	{
		//stop();
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::start(
		size_t numThreads,
		boost::function<void ()> threadStart,
		boost::function<void ()> threadStop)
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
	void Service::balance(size_t numThreads)
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
	void Service::stop()
	{
		ILOG("stop");
		balance(0);
		_threadStart.swap(boost::function<void ()>());
		_threadStop.swap(boost::function<void ()>());
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::post(boost::function<void ()> handler)
	{
		_io_service.post(handler);
	}


	//////////////////////////////////////////////////////////////////////////
	boost::asio::io_service &Service::get_io_service()
	{
		return _io_service;
	}

}
