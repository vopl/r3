#include "resultImpl.hpp"
#include "fromDb2Cpp.hpp"

namespace pgc
{
	ResultImpl::ResultImpl(PGresult *pgres)
		: _pgres(pgres)
	{

	}
	ResultImpl::~ResultImpl()
	{
		if(_pgres)
		{
			PQclear(_pgres);
			_pgres = NULL;
		}
	}

	EExecStatus ResultImpl::status()
	{
		if(_pgres)
		{
			switch(PQresultStatus(_pgres))
			{
			case PGRES_COMMAND_OK:
				return ees_commandOk;
			case PGRES_TUPLES_OK:
				return ees_tuplesOk;
			}
		}
		return ees_error;
	}

	const char *ResultImpl::errorMsg()
	{
		if(_pgres)
		{
			return PQresultErrorMessage(_pgres);
		}
		return "null result";
	}


	size_t ResultImpl::cmdRows()
	{
		if(_pgres)
		{
			return (size_t)atoi(PQcmdTuples(_pgres));
		}
		return 0;
	}
	int ResultImpl::rows()
	{
		if(_pgres)
		{
			return PQntuples(_pgres);
		}
		return 0;
	}

	bool ResultImpl::fetch(int rowIdx, int colIdx, int typIdx, void *data)
	{
		if(!_pgres)
		{
			return false;
		}

		char *val = PQgetvalue(_pgres, rowIdx, colIdx);
		if(!val)
		{
			assert(!"wrong column index");
			return false;
		}

		int fmt = PQfformat(_pgres, colIdx);
		Oid typ = PQftype(_pgres, colIdx);
		int len = PQgetlength(_pgres, rowIdx, colIdx);

		if(0 == fmt)
		{
			//textual
			assert(!"textual format is not supported");
			return false;
		}
		//binary

		return fromDb2Cpp(typIdx, data, typ, len, val);
	}
	bool ResultImpl::fetch(int rowIdx, const char *colName, int typIdx, void *data)
	{
		if(_pgres)
		{
			int cn = PQfnumber(_pgres, colName);
			if(0 > cn)
			{
				return false;
			}

			return fetch(rowIdx, (size_t)cn, typIdx, data);
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::isNull(int rowIdx, int colIdx)
	{
		if(!_pgres)
		{
			return true;
		}

		return PQgetisnull(_pgres, rowIdx, colIdx)?true:false;
	}
	
	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::isNull(int rowIdx, const char *colName)
	{
		if(_pgres)
		{
			int cn = PQfnumber(_pgres, colName);
			if(0 > cn)
			{
				return false;
			}

			return isNull(rowIdx, cn);
		}

		return true;
	}


}