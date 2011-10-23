#include "stdafx.h"
#include "dbMeta/schema.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	Schema::Schema(
		const Manager &manager,
		const std::string &name,
		const CategoryPtrs categories,
		const RelationPtrs relations)
		: _manager(&manager)
		, _name(name)
		, _categories(categories)
		, _relations(relations)
	{

	}
}
