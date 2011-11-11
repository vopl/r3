#include "stdafx.h"
#include "pgs/result.hpp"
#include "impl/result.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Result::Result(Impl_ptr impl)
		: pgc::Result(impl)
	{
	}
}