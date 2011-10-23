#include "stdafx.h"
#include "dbMeta/category.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	Category::Category(
		const Schema &schema,
		const bool isAbstract,
		const std::string &name,
		const FieldPtrs fields,
		const IndexPtrs indices,
		const RelationEndPtrs relationEnds)
		: _schema(&schema)
		, _isAbstract(isAbstract)
		, _name(name)
		, _fields(fields)
		, _indices(indices)
		, _relationEnds(relationEnds)
	{
	}

}

