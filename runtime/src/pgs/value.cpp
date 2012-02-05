#include "pch.h"
#include "pgs/value.hpp"
#include "valueImpl.hpp"
#include "utils/implAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Value::Value(const std::string &alias)
		: Expression(utils::ImplAccess<Expression>(ExpressionImplPtr(new ValueImpl(alias))))
	{

	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Value::alias() const
	{
		return static_cast<ValueImpl *>(_impl.get())->alias();
	}

}
