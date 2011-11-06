#include "stdafx.h"
#include "pgs/expressionSugar.hpp"

namespace pgs
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
		return or_(v1, v2);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression operator&&(const Expression &v1, const Expression &v2)
	{
		return and_(v1, v2);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression operator!(const Expression &v1)
	{
		return not_(v1);
	}

	//////////////////////////////////////////////////////////////////////////
	Expression operator,(const Expression &v1, const Expression &v2)
	{
		return list(v1, v2);
	}

}
