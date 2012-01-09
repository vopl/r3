#ifndef _PGS_ORDERIMPL_HPP_
#define _PGS_ORDERIMPL_HPP_

#include "expressionImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class OrderImpl
		: public ExpressionImpl
	{
	public:
		OrderImpl(...);

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};
	typedef boost::shared_ptr<OrderImpl> OrderImplPtr;
}

#endif
