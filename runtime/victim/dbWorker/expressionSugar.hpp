#ifndef _DBWORKER_EXPRESSIONSUGAR_HPP_
#define _DBWORKER_EXPRESSIONSUGAR_HPP_

#include "dbWorker/expression.hpp"

namespace dbWorker
{
	Expression operator==(const Expression &v1, const Expression &v2);
	Expression operator!=(const Expression &v1, const Expression &v2);

	Expression operator||(const Expression &v1, const Expression &v2);
	Expression operator&&(const Expression &v1, const Expression &v2);

	Expression operator!(const Expression &v1);

	Expression operator,(const Expression &v1, const Expression &v2);

}
#endif
