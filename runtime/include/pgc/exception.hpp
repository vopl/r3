#ifndef _PGC_EXCEPTION_HPP_
#define _PGC_EXCEPTION_HPP_

#include "pgc/common.h"
#include "pgc/result.hpp"

namespace pgc
{
	class ResultImpl;
	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class Exception
		: public std::exception
	{
		ResultImplPtr _res;
	public:
		Exception(ResultImplPtr res);
		Exception(const Exception &from);
		virtual const char *what() const throw ();

		EExecStatus status();
		const char *errorMsg();
		const char *errorCode();

	};
}
#endif
