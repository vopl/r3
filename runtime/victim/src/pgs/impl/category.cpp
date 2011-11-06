#include "stdafx.h"
#include "category.hpp"


namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		Category::Category()
			: _metaCategory()
		{
		}

		//////////////////////////////////////////////////////////////////////////
		Category::Category(pgs::meta::CategoryCPtr cat)
			: _metaCategory(cat)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		pgs::meta::CategoryCPtr Category::meta() const
		{
			return _metaCategory;
		}
	}
}

