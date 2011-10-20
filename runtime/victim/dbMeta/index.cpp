#include "stdafx.h"
#include "dbMeta/index.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	Index::Index(
		const Category &category,
		const EIndexType type,
		const std::string &name,
		const FieldPtrs fields)
		: _category(category)
		, _type(type)
		, _name(name)
		, _fields(fields)
	{
	}

}
