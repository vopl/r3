#include "stdafx.h"
#include "result.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Result::Result(pgc::Result pg)
			: _pg(pg)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		pgc::EExecStatus Result::status()
		{
			return _pg.status();
		}

		//////////////////////////////////////////////////////////////////////////
		size_t Result::cmdRows()
		{
			return _pg.cmdRows();
		}

		//////////////////////////////////////////////////////////////////////////
		size_t Result::rows()
		{
			return _pg.rows();
		}

		//////////////////////////////////////////////////////////////////////////
		bool Result::fetch(size_t rowIdx, size_t colIdx, int typCpp, void *valCpp)
		{
			return _pg.fetchNative(rowIdx, colIdx, typCpp, valCpp);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Result::fetch(size_t rowIdx, const std::string &colName, int typCpp, void *valCpp)
		{
			return _pg.fetchNative(rowIdx, colName.c_str(), typCpp, valCpp);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Result::isNull(size_t rowIdx, size_t colIdx)
		{
			return _pg.isNull(rowIdx, colIdx);
		}

		//////////////////////////////////////////////////////////////////////////
		bool Result::isNull(size_t rowIdx, const std::string &colName)
		{
			return _pg.isNull(rowIdx, colName.c_str());
		}


	}

}