#include "pch.h"
#include "pluma/connector.hpp"
#include "service.hpp"

//PLUMA_CONNECTOR
bool connect(pluma::Host& host){
	// add a keyboard provider to host
	host.add( new async::ServiceProvider() );
	return true;
}