#include "pch.hpp"
#include "pgs/statement.hpp"
#include "statementImpl.hpp"
#include "resultImpl.hpp"

namespace pgs
{


	//////////////////////////////////////////////////////////////////////////
	Statement::Statement(ImplPtr impl)
		: pgc::Statement(impl->getSql())
	{
		//assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	Statement::Statement()
	{

	}

}
