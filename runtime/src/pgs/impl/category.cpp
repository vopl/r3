#include "stdafx.h"
#include "category.hpp"


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
			, _alias(alias)
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

