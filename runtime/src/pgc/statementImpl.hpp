#ifndef _PGC_STATEMENTIMPL_HPP_
#define _PGC_STATEMENTIMPL_HPP_

#include <boost/enable_shared_from_this.hpp>

namespace pgc
{
	using namespace boost;

	class StatementImpl
		: public enable_shared_from_this<StatementImpl>
	{
		std::string _sql;
		std::string _preparedId;

	public:
		StatementImpl(const char *sql);
		StatementImpl(const std::string &sql);
		~StatementImpl();

		const std::string &getSql();

		virtual const std::string &getPreparedId();
		virtual void setPreparedId(const char *csz);
	};

	typedef shared_ptr<StatementImpl> StatementImplPtr;
	typedef weak_ptr<StatementImpl> StatementImplWtr;
}

#endif

