#include "stdafx.h"
#include "pgs/result.hpp"
#include "resultImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Result::Result(Impl_ptr impl)
		: pgc::Result(impl)
	{
	}
}