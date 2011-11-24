#include "stdafx.h"
#include "net/serverSessionManager.hpp"
#include "serverSessionManagerImpl.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	ServerSessionManager::ServerSessionManager(Connector connector, const char *host, const char *service)
		: _impl(new ServerSessionManagerImpl(connector, host, service))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::start(
		boost::function<void (ServerSession)> ready,
		boost::function<void (boost::system::error_code)> fail)
	{
		return _impl->start(ready, fail);
	}

	//////////////////////////////////////////////////////////////////////////
	void ServerSessionManager::stop()
	{
		return _impl->stop();
	}

}
