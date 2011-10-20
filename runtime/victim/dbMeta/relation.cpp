#include "stdafx.h"
#include "dbMeta/relation.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	Relation::Relation(const Schema &schema, const std::string &name)
		: _schema(schema)
		, _name(name)
	{

	}
}


