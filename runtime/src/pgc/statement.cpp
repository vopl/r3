#include "pch.hpp"
#include "pgc/statement.hpp"
#include "statementImpl.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	Statement::Statement()
		: _impl()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Statement::Statement(const char *sql)
		: _impl(new StatementImpl(sql))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Statement::Statement(const std::string &sql)
		: _impl(new StatementImpl(sql))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Statement::~Statement()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Statement::operator bool() const
	{
		return _impl?true:false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Statement::operator!() const
	{
		return _impl?false:true;
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Statement::getSql()
	{
		return _impl->getSql();
	}

}
