#include "stdafx.h"
#include "pgs/statement.hpp"

namespace pgs
{

	//////////////////////////////////////////////////////////////////////////
	Statement::Statement(const Impl_ptr &impl)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	bool Statement::bind(const std::string vname, ...)
	{
		assert(0);
		return false;
	}

	//////////////////////////////////////////////////////////////////////////
	Result Statement::exec(pgc::Connection con)
	{
		assert(0);
		return Result(impl::Result_ptr());
	}

}