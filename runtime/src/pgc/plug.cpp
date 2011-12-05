#include "pch.h"
#include "pluma/connector.hpp"
#include "db.hpp"
#include "statement.hpp"

PLUMA_CONNECTOR
bool pluma_connect(pluma::Host& host)
{
	host.add( new pgc::DbProvider() );
	host.add( new pgc::StatementProvider() );
	return true;
}