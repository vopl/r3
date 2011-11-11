#ifndef _PGS_RESULT_HPP_
#define _PGS_RESULT_HPP_

#include <boost/shared_ptr.hpp>
#include "pgc/connection.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class ResultImpl;
	typedef boost::shared_ptr<ResultImpl> ResultImpl_ptr;

	//////////////////////////////////////////////////////////////////////////
	class Result
		: public pgc::Result
	{
	protected:
		typedef ResultImpl_ptr Impl_ptr;

		friend class Statement;
		Result(Impl_ptr impl);
	};
}
#endif
