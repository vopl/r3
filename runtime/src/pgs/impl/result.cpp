#include "stdafx.h"
#include "result.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Result::Result(...)
			: pgc::ResultImpl(pgc::ConnectionImplPtr(), NULL)
		{
			assert(0);
		}
	}
}