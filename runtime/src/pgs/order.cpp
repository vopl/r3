#include "stdafx.h"
#include "pgs/order.hpp"
#include "implAccess.hpp"
#include "orderImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Order::Order(...)
		: Expression(ImplAccess<Expression>(ImplPtr(new OrderImpl)))
	{
	}
}
