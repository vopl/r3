#ifndef _PGS_ORDER_HPP_
#define _PGS_ORDER_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	class OrderImpl;
	typedef boost::shared_ptr<OrderImpl> OrderImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class Order
		: public Expression
	{
	public:
		typedef OrderImplPtr ImplPtr;

	public:
		Order(...);
	};
}

#endif
