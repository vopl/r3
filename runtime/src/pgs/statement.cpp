#include "stdafx.h"
#include "pgs/statement.hpp"
#include "impl/statement.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	void Statement::bindNative(int typCpp, void const *valCpp, size_t idx)
	{
		return _impl->bind(typCpp, valCpp, idx);
	}
	
	//////////////////////////////////////////////////////////////////////////
	void Statement::bindNative(int typCpp, void const *valCpp, const std::string &name)
	{
		return _impl->bind(typCpp, valCpp, name);
	}


	//////////////////////////////////////////////////////////////////////////
	Statement::Statement(const Impl_ptr &impl)
		: _impl(impl)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::unbind(size_t idx)
	{
		_impl->unbind(idx);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Statement &Statement::unbind(const std::string &name)
	{
		_impl->unbind(name);
		return *this;
	}


	//////////////////////////////////////////////////////////////////////////
	Result Statement::exec()
	{
		return Result(_impl->exec());
	}

}