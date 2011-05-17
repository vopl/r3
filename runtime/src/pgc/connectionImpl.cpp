#include "connectionImpl.hpp"

namespace pgc
{
	ConnectionImpl::ConnectionImpl()
		: _pgcon(NULL)
	{

	}
	ConnectionImpl::~ConnectionImpl()
	{
		close();
	}

	EConnectionStatus ConnectionImpl::open(const char *conninfo)
	{
		close();

		_pgcon = PQconnectdb(conninfo);
		if(_pgcon == NULL)
		{
			return ecs_null;
		}

		return status();
	}
	void ConnectionImpl::close()
	{
		if(_pgcon)
		{
			PQfinish(_pgcon);
			_pgcon = NULL;
		}
	}
	EConnectionStatus ConnectionImpl::status()
	{
		if(!_pgcon)
		{
			return ecs_null;
		}
		return CONNECTION_OK == PQstatus(_pgcon)? ecs_ok : ecs_lost;
	}

	StatementImplPtr ConnectionImpl::once()
	{
		return StatementImplPtr(new StatementImpl(shared_from_this(), true));
	}
	StatementImplPtr ConnectionImpl::prep()
	{
		return StatementImplPtr(new StatementImpl(shared_from_this(), false));
	}
}