#ifndef _PGS_VALUE_HPP_
#define _PGS_VALUE_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class PG_API Value
		: public Expression
	{
	public:

		Value(const std::string &alias);
		const std::string &alias() const;
	};
}

#endif
