#include "pch.h"
#include "dataImpl.hpp"
#include "statementImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	DataImpl::DataImpl(const StatementImplPtr &stm, PGresult *pgres)
		: pgc::DataImpl(pgres, stm->con())
		, _stm(stm)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	bool DataImpl::fldIndex(size_t &res, const pgs::FieldImplPtr &fld)
	{
		return _stm->fldIndex(res, fld);
	}

	bool DataImpl::fldIndices(std::deque<size_t> &res, const pgs::CategoryImplPtr &cat)
	{
		return _stm->fldIndices(res, cat);
	}

}