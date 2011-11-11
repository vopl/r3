#include "stdafx.h"
#include "pgs/value.hpp"
#include "valueImpl.hpp"
#include "implAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Value::Value(const std::string &alias)
		: Expression(ImplAccess<Expression>(ExpressionImpl_ptr(new ValueImpl(alias))))
	{

	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Value::alias() const
	{
		return static_cast<ValueImpl *>(_impl.get())->alias();
	}

}
