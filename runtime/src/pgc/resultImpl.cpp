#include "resultImpl.hpp"
#include "pgc/cppDataType.hpp"

namespace pgc
{
	ResultImpl::ResultImpl(ConnectionImplPtr con, PGresult *pgres)
		: _con(con)
		, _pgres(pgres)
	{
		if(_pgres)
		{
			int cols = PQnfields(_pgres);
			_extractors.resize(cols);

			for(int colIdx(0); colIdx<cols; colIdx++)
			{
				Oid typDb = PQftype(_pgres, colIdx);

				switch(typDb)
				{
				case 21://int2
					_extractors[colIdx]._meth = &ResultImpl::extractor_int2;
					_extractors[colIdx]._favorCppType = CppDataType<boost::int16_t>::cdt_index;
					break;
				case 23://int4
					_extractors[colIdx]._meth = &ResultImpl::extractor_int4;
					_extractors[colIdx]._favorCppType = CppDataType<boost::int32_t>::cdt_index;
					break;
				case 20://int8
					_extractors[colIdx]._meth = &ResultImpl::extractor_int8;
					_extractors[colIdx]._favorCppType = CppDataType<boost::int64_t>::cdt_index;
					break;
				case 1700://numeric
					_extractors[colIdx]._meth = &ResultImpl::extractor_numeric;
					_extractors[colIdx]._favorCppType = CppDataType<std::string>::cdt_index;
					break;
				case 700://float4
					_extractors[colIdx]._meth = &ResultImpl::extractor_float4;
					_extractors[colIdx]._favorCppType = CppDataType<float>::cdt_index;
					break;
				case 701://float8
					_extractors[colIdx]._meth = &ResultImpl::extractor_float8;
					_extractors[colIdx]._favorCppType = CppDataType<double>::cdt_index;
					break;
				case 790://money
					_extractors[colIdx]._meth = &ResultImpl::extractor_money;
					_extractors[colIdx]._favorCppType = CppDataType<boost::int64_t>::cdt_index;
					break;
				case 1043://varchar
				case 1042://bpchar
				case 25://text
					_extractors[colIdx]._meth = &ResultImpl::extractor_varchar;
					_extractors[colIdx]._favorCppType = CppDataType<std::string>::cdt_index;
					break;
				case 17://bytea
					_extractors[colIdx]._meth = &ResultImpl::extractor_bytea;
					_extractors[colIdx]._favorCppType = CppDataType<std::string>::cdt_index;
					break;
				case 1114://timestamp
				case 1184://timestamptz
					_extractors[colIdx]._meth = &ResultImpl::extractor_timestamp;
					_extractors[colIdx]._favorCppType = CppDataType<std::tm>::cdt_index;
					break;
				case 1186://interval
					_extractors[colIdx]._meth = &ResultImpl::extractor_interval;
					_extractors[colIdx]._favorCppType = CppDataType<std::string>::cdt_index;
					break;
				case 1082://date
					_extractors[colIdx]._meth = &ResultImpl::extractor_date;
					_extractors[colIdx]._favorCppType = CppDataType<std::tm>::cdt_index;
					break;
				case 1083://time
				case 1266://timetz
					_extractors[colIdx]._meth = &ResultImpl::extractor_time;
					_extractors[colIdx]._favorCppType = CppDataType<std::tm>::cdt_index;
					break;
				case 16://bool
					_extractors[colIdx]._meth = &ResultImpl::extractor_bool;
					_extractors[colIdx]._favorCppType = CppDataType<bool>::cdt_index;
					break;
				case 1560://bit
				case 1562://varbit
					_extractors[colIdx]._meth = &ResultImpl::extractor_varbit;
					_extractors[colIdx]._favorCppType = CppDataType<std::string>::cdt_index;
					break;
				case 26://oid
					_extractors[colIdx]._meth = &ResultImpl::extractor_oid;
					_extractors[colIdx]._favorCppType = CppDataType<boost::uint32_t>::cdt_index;
					break;
				default:
					_extractors[colIdx]._meth = &ResultImpl::extractor_null;
					_extractors[colIdx]._favorCppType = CppDataType<std::string>::cdt_index;
				}
			}
		}
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

	bool ResultImpl::fetch(int rowIdx, int colIdx, int typCpp, void *valCpp)
	{
		if(!_pgres)
		{
			return false;
		}

		if(colIdx >= (int)_extractors.size())
		{
			return false;
		}

		assert(1 == PQfformat(_pgres, colIdx));

		return (this->*_extractors[colIdx]._meth)(rowIdx, colIdx, typCpp, valCpp);
	}
	bool ResultImpl::fetch(int rowIdx, const char *colName, int typCpp, void *valCpp)
	{
		if(_pgres)
		{
			int cn = PQfnumber(_pgres, colName);
			if(0 > cn)
			{
				return false;
			}

			return fetch(rowIdx, (size_t)cn, typCpp, valCpp);
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