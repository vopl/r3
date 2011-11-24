#include "stdafx.h"
#include "async/service.hpp"
#include "serviceImpl.hpp"
#include "utils/implAccess.hpp"

namespace async
{
	//////////////////////////////////////////////////////////////////////////
	Service::Service()
		: _impl(new ServiceImpl)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void Service::start(
		size_t numThreads,
		boost::function<void ()> threadStart,
		boost::function<void ()> threadStop)
	{
		return _impl->start(numThreads, threadStart, threadStop);
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::balance(size_t numThreads)
	{
		return _impl->balance(numThreads);
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::stop()
	{
		return _impl->stop();
	}

	//////////////////////////////////////////////////////////////////////////
	boost::asio::io_service &Service::get_io_service()
	{
		return _impl->get_io_service();
	}

}
