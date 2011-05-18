#include "pgc/connection.hpp"
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

	Statement Connection::once(const char *sql)
	{
		Statement s(_impl->once());

		if(sql)
		{
			s.sql(sql);
		}

		return s;
	}
	Statement Connection::prep(const char *sql)
	{
		Statement s(_impl->prep());

		if(sql)
		{
			s.sql(sql);
		}

		return s;
	}
}