#ifndef _PGC_IRESULT_HPP_
#define _PGC_IRESULT_HPP_

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	struct IResult
	{
		virtual ~IResult(){}
	};
	typedef boost::shared_ptr<IResult> IResultPtr;
}
#endif
