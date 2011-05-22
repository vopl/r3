#include "pgc/exception.hpp"
#include "resultImpl.hpp"

namespace pgc
{
	Exception::Exception(ResultImplPtr res)
		: std::exception()
		, _res(res)
	{
	}

	Exception::Exception(const Exception &from)
		: std::exception(from)
		, _res(from._res)
	{

	}

	const char *Exception::what() const
	{
		return _res->errorMsg();
	}


	EExecStatus Exception::status()
	{
		return _res->status();
	}

	const char *Exception::errorMsg()
	{
		return _res->errorMsg();
	}

	const char *Exception::errorCode()
	{
		return _res->errorCode();
	}


}
