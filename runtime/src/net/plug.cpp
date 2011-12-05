#include "pch.h"
#include "pluma/connector.hpp"
#include "connector.hpp"


PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new net::ConnectorProvider() );
	return true;
}
