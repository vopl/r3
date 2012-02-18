#include "pch.hpp"
#include "pluma/connector.hpp"
#include "client.hpp"
#include "session.hpp"


PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new client::ClientProvider() );
	return true;
}
