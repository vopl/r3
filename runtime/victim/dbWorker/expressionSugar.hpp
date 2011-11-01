#ifndef _PGS_SUGAR_HPP_
#define _PGS_SUGAR_HPP_

#include "pgs/expr.hpp"

namespace pgs
{
	Expression operator==(const Expression &v1, const Expression &v2);
	Expression operator!=(const Expression &v1, const Expression &v2);

	Expression operator||(const Expression &v1, const Expression &v2);
	Expression operator&&(const Expression &v1, const Expression &v2);

	Expression operator!(const Expression &v1);

	Expression operator,(const Expression &v1, const Expression &v2);

}
#endif
