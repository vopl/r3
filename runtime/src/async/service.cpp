#include "pch.h"
#include "service.hpp"

namespace async
{
	PLUMA_PROVIDER_SOURCE(IService, 1, 1);

	//////////////////////////////////////////////////////////////////////////
	void Service::workerProc(ServiceWorkerPtr swp)
	{
		boost::function<void ()> func0;
		{
			boost::mutex::scoped_lock sl(_mtx);
			func0 = _threadStart;
		}
		if(func0)
		{
			func0();
		}

		boost::system::error_code ec;
		for(;;)
		{
			_io_service.run(ec);
			if(swp->_stop)
			{
				//выкачать остаток сообщений
				_io_service.run(ec);
				break;
			}
			swp->_thread.sleep(boost::get_system_time() + boost::posix_time::milliseconds(500));
		}

		{
			boost::mutex::scoped_lock sl(_mtx);
			func0 = _threadStop;
		}
		if(func0)
		{
			func0();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	Service::Service()
		: _io_service()
		, _work()
		, _threadStart()
		, _threadStop()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Service::~Service()
	{
		stop();
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::start(
		size_t numThreads,
		boost::function<void ()> threadStart,
		boost::function<void ()> threadStop)
	{
		{
			boost::mutex::scoped_lock sl(_mtx);
			assert(!_threadStart);
			_threadStart = threadStart;
			_threadStop = threadStop;
		}
		balance(numThreads);
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::balance(size_t numThreads)
	{
		std::vector<ServiceWorkerPtr> stopped;

		{
			boost::mutex::scoped_lock sl(_mtx);

			while(_workers.size() > numThreads)
			{
				ServiceWorkerPtr &swp = _workers.back();
				swp->_stop = true;
				stopped.push_back(swp);
				_workers.pop_back();
			}
			while(_workers.size() < numThreads)
			{
				ServiceWorkerPtr swp(new ServiceWorker);
				swp->_stop = false;
				swp->_thread = boost::thread(boost::bind(&Service::workerProc, shared_from_this(), swp));
				_workers.push_back(swp);
			}
			_work.reset();

			if(_workers.empty())
			{
				_io_service.stop();
			}
		}

		BOOST_FOREACH(ServiceWorkerPtr &swp, stopped)
		{
			swp->_thread.join();
		}

		{
			boost::mutex::scoped_lock sl(_mtx);
			if(_workers.empty())
			{
				//выкачать остаток из этого потока
				boost::system::error_code ec;
				_io_service.reset();
				_io_service.run(ec);
			}
			else
			{
				_io_service.reset();
				_work.reset(new boost::asio::io_service::work(_io_service));
			}

		}
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::stop()
	{
		balance(0);
	}

	//////////////////////////////////////////////////////////////////////////
	boost::asio::io_service &Service::get_io_service()
	{
		return _io_service;
	}

}
