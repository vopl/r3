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

	void Connection::log(std::ostream &out, int flags)
	{
		_impl->log(out, flags);
	}

	EConnectionStatus Connection::open(const char *conninfo)
	{
		return _impl->open(conninfo);
	}
	EConnectionStatus Connection::ping(bool forceReset)
	{
		return _impl->ping(forceReset);
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

	Statement Connection::once(const std::string &sql)
	{
		Statement s(_impl->once());
		s.sql(sql);

		return s;
	}
	Statement Connection::prep(const std::string &sql)
	{
		Statement s(_impl->prep());
		s.sql(sql.c_str());

		return s;
	}

}