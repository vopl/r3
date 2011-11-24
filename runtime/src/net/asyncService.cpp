#include "stdafx.h"
#include "net/asyncService.hpp"
#include "asyncServiceImpl.hpp"
#include "utils/implAccess.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	AsyncService::AsyncService()
		: _impl(new AsyncServiceImpl)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void AsyncService::start(
		size_t numThreads,
		boost::function<void ()> threadStart,
		boost::function<void ()> threadStop)
	{
		return _impl->start(numThreads, threadStart, threadStop);
	}

	//////////////////////////////////////////////////////////////////////////
	void AsyncService::balance(size_t numThreads)
	{
		return _impl->balance(numThreads);
	}

	//////////////////////////////////////////////////////////////////////////
	void AsyncService::stop()
	{
		return _impl->stop();
	}
}
