#include "pgc/exception.hpp"
#include "resultImpl.hpp"

namespace pgc
{
	Exception::Exception(ResultImplPtr res)
		: std::exception(res->errorMsg())
	{

	}


}
