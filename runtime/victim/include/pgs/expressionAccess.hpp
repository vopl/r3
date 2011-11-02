#ifndef _DBWORKER_EXPRESSIONACCESS_HPP_
#define _DBWORKER_EXPRESSIONACCESS_HPP_

#include "dbWorker/expression.hpp"

namespace dbWorker
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
