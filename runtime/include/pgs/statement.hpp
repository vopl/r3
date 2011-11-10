#ifndef _PGS_STATEMENT_HPP_
#define _PGS_STATEMENT_HPP_

#include "pgs/result.hpp"
#include <boost/shared_ptr.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	namespace impl
	{
		class Statement;
		typedef boost::shared_ptr<Statement> Statement_ptr;
	}

	//////////////////////////////////////////////////////////////////////////
	class Statement
	{
	protected:
		typedef impl::Statement_ptr Impl_ptr;
		Impl_ptr _impl;
	public:
		Statement(const Impl_ptr &impl);

		bool bind(const std::string vname, ...);
		Result exec(pgc::Connection con);
	};

}
#endif
