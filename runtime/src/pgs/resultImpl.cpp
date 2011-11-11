#include "stdafx.h"
#include "resultImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	ResultImpl::ResultImpl(pgc::ConnectionImplPtr con, PGresult *pgres)
		: pgc::ResultImpl(con, pgres)
	{
	}
}