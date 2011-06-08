#include "net/service.hpp"
#include "serviceImpl.hpp"

namespace net
{

	//////////////////////////////////////////////////////////////////////////
	Service::Service(IServiceHandler *handler)
		: _impl(new ServiceImpl(handler))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::balance(size_t numThreads)
	{
		_impl->balance(numThreads);

	}

	//////////////////////////////////////////////////////////////////////////
	void Service::listen(const char *host, short port)
	{
		_impl->listen(host, port);
	}

	//////////////////////////////////////////////////////////////////////////
	void Service::connect(const char *host, short port)
	{
		_impl->connect(host, port);
	}


}
