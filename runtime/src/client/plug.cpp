#include "pch.h"
#include "pluma/connector.hpp"
#include "client.hpp"
#include "session.hpp"
#include "agentHub.hpp"


PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new client::ClientProvider() );
	host.add( new client::SessionProvider() );
	host.add( new client::AgentHubProvider() );
	return true;
}