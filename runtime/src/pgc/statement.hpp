#ifndef _PGC_STATEMENT_HPP_
#define _PGC_STATEMENT_HPP_

#include "pgc/istatement.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace pgc
{
	using namespace boost;

	class Statement
		: public IStatement
		, public enable_shared_from_this<Statement>
	{
	public:
		Statement();
		~Statement();
	};

	PLUMA_INHERIT_PROVIDER(Statement, IStatement);
}

#endif

