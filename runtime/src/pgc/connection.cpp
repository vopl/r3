#include "pch.h"
#include "connection.hpp"
#include "db.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	Connection::Connection(DbPtr db, PGconnWrapperPtr con)
		: _db(db)
		, _con(con)
	{
	}
	
	//////////////////////////////////////////////////////////////////////////
	Connection::~Connection()
	{
		_db->unwork(_con);
	}

	//////////////////////////////////////////////////////////////////////////
	void Connection::exec(IStatementPtr s,
		function<void (IResultPtr)> done)
	{
		assert(0);
	}
}
