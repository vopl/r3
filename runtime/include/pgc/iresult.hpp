#ifndef _PGC_IRESULT_HPP_
#define _PGC_IRESULT_HPP_

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	enum EExecStatus
	{
		eesCommandOk,
		eesTuplesOk,
		eesError,
	};

	//////////////////////////////////////////////////////////////////////////
	struct IResult
	{
		virtual ~IResult(){}

		virtual EExecStatus status() = 0;
		virtual const char *errorMsg() = 0;
		virtual const char *errorCode() = 0;

		virtual size_t cmdRows() = 0;

	};
	typedef boost::shared_ptr<IResult> IResultPtr;
}
#endif
