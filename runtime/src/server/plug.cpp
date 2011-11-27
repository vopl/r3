#include "pch.h"
#include "pluma/connector.hpp"
#include "server.hpp"


PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new server::ServerProvider() );
	return true;
}