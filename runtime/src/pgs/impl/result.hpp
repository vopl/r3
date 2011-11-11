#ifndef _PGS_IMPL_RESULT_HPP_
#define _PGS_IMPL_RESULT_HPP_

#include "../../pgc/resultImpl.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Result
			: public pgc::ResultImpl
		{
		public:
			Result(pgc::ConnectionImplPtr con, PGresult *pgres);
		};
		typedef boost::shared_ptr<Result> Result_ptr;
	}
}

#endif
