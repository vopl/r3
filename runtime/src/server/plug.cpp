#include "pch.h"
#include "pluma/connector.hpp"
#include "server.hpp"
#include "sessionManager.hpp"

#include "serviceHub.hpp"
#include "serviceEcho.hpp"


PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new server::ServerProvider() );
	host.add( new server::SessionManagerProvider() );

	host.add( new server::ServiceHubProvider() );
	host.add( new server::ServiceEchoProvider() );

	return true;
}