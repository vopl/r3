#ifndef _PGS_RESULT_HPP_
#define _PGS_RESULT_HPP_

#include <boost/shared_ptr.hpp>
#include "pgc/connection.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	namespace impl
	{
		class Result;
		typedef boost::shared_ptr<Result> Result_ptr;
	}

	//////////////////////////////////////////////////////////////////////////
	class Result
		: public pgc::Result
	{
	protected:
		typedef impl::Result_ptr Impl_ptr;

	public:
		Result(...);
	};
}
#endif
