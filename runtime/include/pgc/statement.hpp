#ifndef _PGC_STATEMENT_HPP_
#define _PGC_STATEMENT_HPP_

#include "pgc/api.h"
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Statement
	{
	protected:
		typedef StatementImplPtr ImplPtr;
		ImplPtr	_impl;

	public:
		Statement();
		Statement(const char *sql);
		Statement(const std::string &sql);
		~Statement();

		operator bool() const;
		bool operator!() const;

		const std::string &getSql();
	};
}
#endif
