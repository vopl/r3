#include "pgs/sugar.hpp"

namespace pgs
{
	Expr operator==(const Expr &v1, const Expr &v2)
	{
		return eq(v1, v2);
	}
	Expr operator!=(const Expr &v1, const Expr &v2)
	{
		return ne(v1, v2);
	}

	Expr operator||(const Expr &v1, const Expr &v2)
	{
		return or(v1, v2);
	}
	Expr operator&&(const Expr &v1, const Expr &v2)
	{
		return and(v1, v2);
	}

	Expr operator!(const Expr &v1)
	{
		return not(v1);
	}
}
