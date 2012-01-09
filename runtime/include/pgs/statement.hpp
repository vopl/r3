#ifndef _PGS_STATEMENT_HPP_
#define _PGS_STATEMENT_HPP_

#include "pgs/data.hpp"
#include <boost/shared_ptr.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class StatementImpl;
	typedef boost::shared_ptr<StatementImpl> StatementImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class Statement
		: public pgc::Statement
	{
	protected:
		typedef StatementImplPtr ImplPtr;

		friend class Select;
		Statement(ImplPtr impl);
	public:


		Data exec();
	};
}
#endif
