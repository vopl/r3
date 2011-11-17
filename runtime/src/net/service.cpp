#include "stdafx.h"
#include "net/service.hpp"
#include "serviceImpl.hpp"

namespace net
{

	//////////////////////////////////////////////////////////////////////////
	Service::Service(IServiceHandler *handler)
	{
		_impl.reset(new ServiceImpl(this, handler));
	}

	//////////////////////////////////////////////////////////////////////////
	Service::~Service()
	{
		_impl.reset();
	}


	//////////////////////////////////////////////////////////////////////////
	void Service::balance(size_t numThreads)
	{
		_impl->balance(numThreads);

	}

	//////////////////////////////////////////////////////////////////////////
	bool Service::listen(const char *host, short port)
	{
		return _impl->listen(host, port);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Service::connect(const char *host, short port)
	{
		return _impl->connect(host, port);
	}


}
