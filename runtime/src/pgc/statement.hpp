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
		std::string _sql;
		std::string _preparedId;

	public:
		Statement();
		~Statement();

		virtual void setSql(const char *csz);
		virtual void setSql(const std::string &sql);
		virtual const std::string &getSql();

		virtual const std::string &getPreparedId();
		virtual void setPreparedId(const char *csz);
	};

	PLUMA_INHERIT_PROVIDER(Statement, IStatement);
}

#endif

