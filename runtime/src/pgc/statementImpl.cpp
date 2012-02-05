#include "pch.h"
#include "statementImpl.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	StatementImpl::StatementImpl(const char *sql)
		: _sql(sql)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	StatementImpl::StatementImpl(const std::string &sql)
		: _sql(sql)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	StatementImpl::~StatementImpl()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &StatementImpl::getSql()
	{
		return _sql;
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &StatementImpl::getPreparedId()
	{
		return _preparedId;
	}

	//////////////////////////////////////////////////////////////////////////
	void StatementImpl::setPreparedId(const char *csz)
	{
		_preparedId = csz;
	}

}
