#include "stdafx.h"
#include "pgs/order.hpp"
#include "impl/access.hpp"
#include "impl/order.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Order::Order(...)
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Order)))
	{
	}
}
