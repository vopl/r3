#include "pch.h"
#include "connectionHolder.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	ConnectionHolder::ConnectionHolder(DbPtr db, ConnectionPreparedsPtr con)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionHolder::~ConnectionHolder()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::exec(const char *sql,
		boost::function<void (IResultPtr)> done)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::exec(IStatementPtr s,
		boost::function<void (IResultPtr)> done)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::exec(IStatementPtr s,
		const utils::Variant &data,
		boost::function<void (IResultPtr)> done)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	EConnectionStatus ConnectionHolder::status()
	{
		assert(0);
		return ecsNull;
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::close()
	{
		assert(0);
	}

}
