#include "pch.h"
#include "pluma/connector.hpp"
#include "server.hpp"
#include "sessionManager.hpp"

#include "nodeManager.hpp"
#include "serviceEcho.hpp"
#include "serviceStatics.hpp"
#include "serviceVictim.hpp"


PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new server::ServerProvider() );
	host.add( new server::SessionManagerProvider() );

	host.add( new server::NodeManagerProvider() );

	host.add( new server::ServiceEchoProvider() );
	host.add( new server::ServiceStaticsProvider() );
	host.add( new server::ServiceVictimProvider() );

	return true;
}
