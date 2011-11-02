#ifndef _PGS_EXPRESSIONACCESS_HPP_
#define _PGS_EXPRESSIONACCESS_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	class ExpressionAccess
		: public Expression
	{
	public:
		ExpressionAccess(const Expression &expr);
		ExpressionAccess(const ExpressionImpl_ptr &impl);

		ExpressionImpl_ptr &impl();
		operator ExpressionImpl_ptr&();
	};

}

#endif
