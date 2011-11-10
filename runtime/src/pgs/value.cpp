#include "stdafx.h"
#include "pgs/value.hpp"
#include "impl/value.hpp"
#include "impl/access.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Value::Value(const std::string &alias, const std::string &srcAlias)
		: Expression(impl::Access<Expression>(impl::Expression_ptr(new impl::Value(alias, srcAlias))))
	{

	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Value::srcAlias() const
	{
		return static_cast<impl::Value *>(_impl.get())->srcAlias();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Value::alias() const
	{
		return static_cast<impl::Value *>(_impl.get())->alias();
	}

}
