#include "pch.h"
#include "pluma/connector.hpp"
#include "server.hpp"
#include "sessionManager.hpp"


PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new server::ServerProvider() );
	host.add( new server::SessionManagerProvider() );
	return true;
}