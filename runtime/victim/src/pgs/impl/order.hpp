#ifndef _PGS_IMPL_ORDER_HPP_
#define _PGS_IMPL_ORDER_HPP_

#include "expression.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Order
			: public Expression
		{
		public:
			Order(...);
		};
		typedef boost::shared_ptr<Order> Order_ptr;
	}
}

#endif
