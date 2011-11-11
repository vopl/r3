#ifndef _PGS_IMPL_RESULT_HPP_
#define _PGS_IMPL_RESULT_HPP_

#include "../pgc/resultImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ResultImpl
		: public pgc::ResultImpl
	{
	public:
		ResultImpl(pgc::ConnectionImplPtr con, PGresult *pgres);
	};
	typedef boost::shared_ptr<ResultImpl> ResultImpl_ptr;
}

#endif
