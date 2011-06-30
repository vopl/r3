#ifndef _PGS_EXPRACCESS_HPP_
#define _PGS_EXPRACCESS_HPP_

#include "pgs/expr.hpp"

namespace pgs
{
	class ExprAccess
		: public Expr
	{
	public:
		ExprAccess(const Expr &expr);
		ExprAccess(const ExprImpl_ptr &impl);

		ExprImpl_ptr &impl();
		operator ExprImpl_ptr&();
	};

}

#endif
