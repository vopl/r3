#include "stdafx.h"
#include "dbWorker/expressionAccess.hpp"

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	ExpressionAccess::ExpressionAccess(const Expression &expr)
		: Expression(expr)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionAccess::ExpressionAccess(const ExpressionImpl_ptr &impl)
	{
		_impl = impl;
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionImpl_ptr &ExpressionAccess::impl()
	{
		return _impl;
	}

	//////////////////////////////////////////////////////////////////////////
	ExpressionAccess::operator ExpressionImpl_ptr&()
	{
		return _impl;
	}

}


