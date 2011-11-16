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
	bool Statement::bindNative(int typCpp, void const *valCpp, const char *name)
	{
		return boost::static_pointer_cast<StatementImpl>(_impl)->bind(typCpp, valCpp, name);
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::bind(const utils::Variant &v, const char *name)
	{
		if(!boost::static_pointer_cast<StatementImpl>(_impl)->bind(v.type(), v.data(), name))
		{
			throw std::invalid_argument("for Statement::bind");
		}
		return *this;
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
		ResultImpl_ptr res(new ResultImpl(
			boost::static_pointer_cast<StatementImpl>(_impl), 
			_impl->exec()));
		return Result(res);
	}



}