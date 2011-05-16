#ifndef _PGC_EXCEPTION_HPP_
#define _PGC_EXCEPTION_HPP_

namespace pgc
{
	class ResultImpl;
	typedef boost::shared_ptr<ResultImpl> ResultImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class Exception
		: public std::exception
	{
	public:
		Exception(ResultImplPtr res);
	};
}
#endif