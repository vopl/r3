#include "stdafx.h"
#include "category.hpp"
#include "pgs/meta/category.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Category::Category()
			: _metaCategory()
			, _alias()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Category::Category(pgs::meta::CategoryCPtr cat, const std::string &alias)
			: _metaCategory(cat)
			, _alias(alias.empty()?cat->_name:alias)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		pgs::meta::CategoryCPtr Category::meta() const
		{
			return _metaCategory;
		}

		//////////////////////////////////////////////////////////////////////////
		const std::string &Category::alias() const
		{
			return _alias;
		}

	}
}

