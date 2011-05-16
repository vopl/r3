#include "stdafx.h"
#include "connection.hpp"
#include "connectionImpl.hpp"

namespace pgc
{
	Connection::Connection()
		: _impl(new ConnectionImpl)
	{

	}
	Connection::~Connection()
	{
		_impl.reset();
	}

	EConnectionStatus Connection::open(const char *conninfo)
	{
		return _impl->open(conninfo);
	}
	void Connection::close()
	{
		return _impl->close();
	}
	EConnectionStatus Connection::status()
	{
		return _impl->status();
	}

	Statement Connection::once()
	{
		return Statement(_impl->once());
	}
	Statement Connection::prep()
	{
		return Statement(_impl->prep());
	}
}