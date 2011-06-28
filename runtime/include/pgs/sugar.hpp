#ifndef _PGS_SUGAR_HPP_
#define _PGS_SUGAR_HPP_

#include "pgs/expr.hpp"

namespace pgs
{
	Expr operator==(const Expr &v1, const Expr &v2)
	{
		return eq(v1, v2);
	}

	Expr operator||(const Expr &v1, const Expr &v2)
	{
		return or(v1, v2);
	}
}
#endif
