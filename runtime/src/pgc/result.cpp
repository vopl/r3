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

	//////////////////////////////////////////////////////////////////////////
	const char *Result::errorMsg()
	{
		if(_pgr)
		{
			const char *res = PQresultErrorMessage(_pgr);
			return res?res:"";
		}
		return "null result";
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::errorCode()
	{
		if(_pgr)
		{
			const char *res = PQresultErrorField(_pgr, PG_DIAG_SQLSTATE);
			return res?res:"";
		}
		return "null result";
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::cmdRows()
	{
		if(_pgr)
		{
			return utils::_atost(PQcmdTuples(_pgr));
		}
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::rows()
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::cols()
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	size_t Result::colIdx(const char *colName)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	const char *Result::colName(size_t colIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::isNull(size_t rowIdx, size_t colIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	utils::Variant::EType Result::type(size_t rowIdx, size_t colIdx)
	{
		assert(0);
		return utils::Variant::etUnknown;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetch(utils::Variant &v, size_t rowIdx, size_t colIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowList(utils::Variant &v, size_t rowIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowMap(utils::Variant &v, size_t rowIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsList(utils::Variant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsMap(utils::Variant &v, size_t rowBeginIdx, size_t rowEndIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsList(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchRowsMap(utils::Variant &v, const std::deque<size_t> &colIndices, size_t rowBeginIdx, size_t rowEndIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Result::fetchColumn(utils::Variant &v, size_t colIdx, size_t rowBeginIdx, size_t rowEndIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	boost::int32_t Result::fetchInt32(size_t rowIdx, size_t colIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	boost::uint32_t Result::fetchUInt32(size_t rowIdx, size_t colIdx)
	{
		assert(0);
		return 0;
	}

	//////////////////////////////////////////////////////////////////////////
	std::string Result::fetchString(size_t rowIdx, size_t colIdx)
	{
		assert(0);
		return "";
	}

}
