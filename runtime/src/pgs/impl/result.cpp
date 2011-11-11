#include "stdafx.h"
#include "result.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Result::Result(pgc::ConnectionImplPtr con, PGresult *pgres)
			: pgc::ResultImpl(con, pgres)
		{
		}
	}
}