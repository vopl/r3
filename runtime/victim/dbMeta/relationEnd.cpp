#include "stdafx.h"
#include "dbMeta/relationEnd.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	RelationEnd::RelationEnd(const Relation &relation, ERelationMult mult)
		: _relation(&relation)
		, _mult(mult)
		, __category(NULL)
		, _category(__category)
		, _categories(__categories)
	{

	}
}


