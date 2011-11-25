#include "pch.h"
#include "pluma/connector.hpp"
#include "service.hpp"


PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new async::ServiceProvider() );
	return true;
}