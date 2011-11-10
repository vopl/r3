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
	{
	protected:
		typedef impl::Result_ptr Impl_ptr;
		Impl_ptr _impl;
	public:
		Result(const Impl_ptr &impl);

		pgc::EExecStatus status();
		size_t rows();
		bool fetch(...);
	};

}
#endif
