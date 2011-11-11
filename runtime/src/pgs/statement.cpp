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
	void Statement::bindNative(int typCpp, void const *valCpp, const char *name)
	{
		boost::static_pointer_cast<impl::Statement>(_impl)->bind(typCpp, valCpp, name);
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::unbind(const char *name)
	{
		boost::static_pointer_cast<impl::Statement>(_impl)->unbind(name);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Result Statement::exec()
	{
		impl::Result_ptr res(new impl::Result(_impl->con(), _impl->exec()));
		return Result(res);
	}



}