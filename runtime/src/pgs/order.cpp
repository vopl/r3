#include "pch.hpp"
#include "pgs/order.hpp"
#include "utils/implAccess.hpp"
#include "orderImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Order::Order(...)
		: Expression(utils::ImplAccess<Expression>(ImplPtr(new OrderImpl)))
	{
	}
}
