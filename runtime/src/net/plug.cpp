#include "pch.h"
#include "pluma/connector.hpp"
#include "connector.hpp"
#include "serverSessionManager.hpp"
#include "clientSession.hpp"


PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new net::ConnectorProvider() );
	host.add( new net::ServerSessionManagerProvider() );
	host.add( new net::ClientSessionProvider() );
	return true;
}