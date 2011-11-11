#include "stdafx.h"
#include "pgs/statement.hpp"
#include "impl/statement.hpp"
#include "impl/result.hpp"

namespace pgs
{


	//////////////////////////////////////////////////////////////////////////
	Statement::Statement(Impl_ptr impl)
		: pgc::Statement(impl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Result Statement::exec()
	{
		impl::Result_ptr res(new impl::Result(_impl->con(), _impl->exec()));
		return Result(res);
	}



}