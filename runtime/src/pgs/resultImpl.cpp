#include "stdafx.h"
#include "resultImpl.hpp"
#include "statementImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	ResultImpl::ResultImpl(const StatementImpl_ptr &stm, PGresult *pgres)
		: pgc::ResultImpl(stm->con(), pgres)
		, _stm(stm)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	bool ResultImpl::fldIndex(size_t &res, const pgs::FieldImpl_ptr &fld)
	{
		return _stm->fldIndex(res, fld);
	}

	bool ResultImpl::fldIndices(std::deque<size_t> &res, const pgs::CategoryImpl_ptr &cat)
	{
		return _stm->fldIndices(res, cat);
	}

}