#ifndef _PGS_STATEMENT_HPP_
#define _PGS_STATEMENT_HPP_

#include "pgs/result.hpp"
#include <boost/shared_ptr.hpp>
#include "pgc/statement.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Statement
		: public pgc::Statement
	{
	protected:
		typedef StatementImplPtr ImplPtr;

		friend class Select;
		Statement(ImplPtr impl);
	public:


		//Data exec();
	};
}
#endif
