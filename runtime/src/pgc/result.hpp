#ifndef _PGC_RESULT_HPP_
#define _PGC_RESULT_HPP_

#include "pgc/iresult.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace pgc
{
	using namespace boost;

	class Result
		: public IResult
		, public enable_shared_from_this<Result>
	{
	public:
		Result();
		~Result();
	};
}

#endif

