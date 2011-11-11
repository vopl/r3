#ifndef _PGS_ORDER_HPP_
#define _PGS_ORDER_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	class OrderImpl;
	typedef boost::shared_ptr<OrderImpl> OrderImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class Order
		: public Expression
	{
	public:
		typedef OrderImpl_ptr Impl_ptr;

	public:
		Order(...);
	};
}

#endif
