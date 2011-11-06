#ifndef _PGS_ORDER_HPP_
#define _PGS_ORDER_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	namespace impl
	{
		class Order;
		typedef boost::shared_ptr<Order> Order_ptr;
	}

	//////////////////////////////////////////////////////////////////////////
	class Order
		: public Expression
	{
	public:
		typedef impl::Order_ptr Impl_ptr;

	public:
		Order(...);
	};
}

#endif
