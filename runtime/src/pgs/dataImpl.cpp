#include "pch.h"
#include "resultImpl.hpp"
#include "statementImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	ResultImpl::ResultImpl(const StatementImplPtr &stm, PGresult *pgres)
		: pgc::ResultImpl(stm->con(), pgres)
		, _stm(stm)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::fldIndex(size_t &res, const pgs::FieldImplPtr &fld)
	{
		return _stm->fldIndex(res, fld);
	}

	bool ResultImpl::fldIndices(std::deque<size_t> &res, const pgs::CategoryImplPtr &cat)
	{
		return _stm->fldIndices(res, cat);
	}

}