#include "stdafx.h"
#include "pgs/statement.hpp"
#include "statementImpl.hpp"
#include "resultImpl.hpp"

namespace pgs
{


	//////////////////////////////////////////////////////////////////////////
	Statement::Statement(Impl_ptr impl)
		: pgc::Statement(impl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void Statement::bindNative(int typCpp, void const *valCpp, const char *name)
	{
		boost::static_pointer_cast<StatementImpl>(_impl)->bind(typCpp, valCpp, name);
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::unbind(const char *name)
	{
		boost::static_pointer_cast<StatementImpl>(_impl)->unbind(name);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Result Statement::exec()
	{
		ResultImpl_ptr res(new ResultImpl(_impl->con(), _impl->exec()));
		return Result(res);
	}



}