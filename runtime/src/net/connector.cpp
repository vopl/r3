#include "pch.h"
#include "net/connector.hpp"
#include "utils/implAccess.hpp"
#include "connectorImpl.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	Connector::Connector(async::Service asrv)
		: _impl(new ConnectorImpl(asrv))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::listen(
		const char *host, const char *service,
		boost::function<void (Channel)> ok,
		boost::function<void (boost::system::error_code)> fail)
	{
		return _impl->listen(host, service, ok, fail);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Connector::unlisten(const char *host, const char *service)
	{
		return _impl->unlisten(host, service);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connector::connect(
		const char *host, const char *service,
		boost::function<void (Channel)> ok,
		boost::function<void (boost::system::error_code)> fail)
	{
		return _impl->connect(host, service, ok, fail);
	}

}
