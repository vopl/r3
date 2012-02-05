#ifndef _PGS_EXPRESSIONSUGAR_HPP_
#define _PGS_EXPRESSIONSUGAR_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	Expression operator==(const Expression &v1, const Expression &v2);
	Expression operator!=(const Expression &v1, const Expression &v2);

	//////////////////////////////////////////////////////////////////////////
	Expression operator>(const Expression &v1, const Expression &v2);
	Expression operator>=(const Expression &v1, const Expression &v2);
	Expression operator<(const Expression &v1, const Expression &v2);
	Expression operator<=(const Expression &v1, const Expression &v2);


	//////////////////////////////////////////////////////////////////////////
	Expression operator||(const Expression &v1, const Expression &v2);
	Expression operator&&(const Expression &v1, const Expression &v2);
	Expression operator!(const Expression &v1);

	Expression operator,(const Expression &v1, const Expression &v2);

	//////////////////////////////////////////////////////////////////////////
	Expression operator+(const Expression &v1, const Expression &v2);
	Expression operator-(const Expression &v1, const Expression &v2);
	Expression operator*(const Expression &v1, const Expression &v2);
	Expression operator/(const Expression &v1, const Expression &v2);
	Expression operator%(const Expression &v1, const Expression &v2);
	Expression operator^(const Expression &v1, const Expression &v2);

}
#endif
