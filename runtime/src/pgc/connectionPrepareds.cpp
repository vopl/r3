#include "pch.h"
#include "connectionPrepareds.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	ConnectionPrepareds::ConnectionPrepareds(PGconn *pgcon, asio::io_service &io_service)
		: ConnectionRunner(pgcon, io_service)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionPrepareds::~ConnectionPrepareds()
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::exec(IStatementPtr s,
		boost::function<void (IResultPtr)> done)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionPrepareds::exec(IStatementPtr s,
		BindDataPtr data,
		boost::function<void (IResultPtr)> done)
	{
		assert(0);
	}

}
