#include "connectionImpl.hpp"
#include "statementImpl.hpp"
#include "statementPrepImpl.hpp"

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

	PGconn *ConnectionImpl::pgcon()
	{
		return _pgcon;
	}

	EConnectionStatus ConnectionImpl::open(const char *conninfo)
	{
		close();

		_pgcon = PQconnectdb(conninfo);
		if(_pgcon == NULL)
		{
			return ecs_null;
		}
		PQsetClientEncoding(_pgcon, "UTF-8");

		EConnectionStatus s = status();

		if(ecs_ok == s)
		{
			PQsetClientEncoding(_pgcon, "UTF-8");
		}

		return s;
	}

	EConnectionStatus ConnectionImpl::reset()
	{
		if(_pgcon)
		{
			PQreset(_pgcon);
		}

		EConnectionStatus s = status();

		if(ecs_ok == s)
		{
			PQsetClientEncoding(_pgcon, "UTF-8");
		}

		return s;
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
		return StatementImplPtr(new StatementImpl(shared_from_this()));
	}
	StatementImplPtr ConnectionImpl::prep()
	{
		return StatementImplPtr(new StatementPrepImpl(shared_from_this()));
	}
}