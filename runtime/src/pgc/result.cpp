#include "pch.h"
#include "result.hpp"
#include <libpq-fe.h>
#include "utils/aton.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	Result::Result(PGresult *pgr)
		: _pgr(pgr)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Result::~Result()
	{
		PQclear(_pgr);
	}

	//////////////////////////////////////////////////////////////////////////
	EExecStatus Result::status()
	{
		if(_pgr)
		{
			switch(PQresultStatus(_pgr))
			{
			case PGRES_EMPTY_QUERY:
			case PGRES_COMMAND_OK:
				return eesCommandOk;
			case PGRES_TUPLES_OK:
				return eesTuplesOk;
			}
		}
		return eesError;
	}

	const char *Result::errorMsg()
	{
		if(_pgr)
		{
			return PQresultErrorMessage(_pgr);
		}
		return "null result";
	}

	const char *Result::errorCode()
	{
		if(_pgr)
		{
			return PQresultErrorField(_pgr, PG_DIAG_SQLSTATE);
		}
		return "null";
	}



	size_t Result::cmdRows()
	{
		if(_pgr)
		{
			return utils::_atost(PQcmdTuples(_pgr));
		}
		return 0;
	}

}
