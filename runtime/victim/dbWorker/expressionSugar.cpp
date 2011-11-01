#include "stdafx.h"
#include "dbWorker/expressionSugar.hpp"

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	Expression operator==(const Expression &v1, const Expression &v2)
	{
		return eq(v1, v2);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression operator!=(const Expression &v1, const Expression &v2)
	{
		return ne(v1, v2);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression operator||(const Expression &v1, const Expression &v2)
	{
		return or(v1, v2);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression operator&&(const Expression &v1, const Expression &v2)
	{
		return and(v1, v2);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression operator!(const Expression &v1)
	{
		return not(v1);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression operator,(const Expression &v1, const Expression &v2)
	{
		return list(v1, v2);
	}

}
