#include "pch.h"
#include "pgc/db.hpp"
#include "dbImpl.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	Db::Db()
		: _impl()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Db::Db(const char *conninfo,
		size_t maxConnections,
		boost::function<void (size_t)> connectionMade,
		boost::function<void (size_t)> connectionLost)
		: _impl(new DbImpl(conninfo, maxConnections, connectionMade, connectionLost))
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Db::~Db()
	{
		_impl.reset();
	}

	//////////////////////////////////////////////////////////////////////////
	Db::operator bool() const
	{
		return _impl?true:false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Db::operator!() const
	{
		return _impl?false:true;
	}

	//////////////////////////////////////////////////////////////////////////
	void Db::reset()
	{
		_impl.reset();
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<Connection> Db::allocConnection()
	{
		return _impl->allocConnection();
	}
}
