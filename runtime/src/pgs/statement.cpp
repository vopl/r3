#include "pch.h"
#include "pgs/statement.hpp"
#include "statementImpl.hpp"
#include "dataImpl.hpp"

namespace pgs
{


	//////////////////////////////////////////////////////////////////////////
	Statement::Statement(ImplPtr impl)
		: pgc::Statement("sql here")
	{
		assert(0);
	}
}