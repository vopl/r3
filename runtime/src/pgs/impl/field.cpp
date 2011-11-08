#include "stdafx.h"
#include "field.hpp"
#include "pgs/meta/category.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Field::Field()
			: _srcAlias()
			, _metaField()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Field::Field(pgs::meta::FieldCPtr fld)
			: _srcAlias(fld->_category->_name)
			, _metaField(fld)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Field::Field(const std::string srcAlias, pgs::meta::FieldCPtr fld)
			: _srcAlias(srcAlias)
			, _metaField(fld)
		{

		}

		//////////////////////////////////////////////////////////////////////////
		pgs::meta::FieldCPtr Field::meta() const
		{
			return _metaField;
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string &Field::srcAlias() const
		{
			return _srcAlias;
		}
	}
}
