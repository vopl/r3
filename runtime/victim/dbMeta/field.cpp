#include "stdafx.h"
#include "dbMeta/field.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	Field::Field(
		const Category &category,
		const EFieldType type,
		const std::string &name,
		const bool allowNull)
		: _category(category)
		, _type(type)
		, _name(name)
		, _allowNull(allowNull)
	{
	}
}
