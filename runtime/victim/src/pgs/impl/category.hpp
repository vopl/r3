#ifndef _PGS_IMPL_CATEGORY_HPP_
#define _PGS_IMPL_CATEGORY_HPP_

#include "pgs/category.hpp"
#include "expression.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Category
			: public impl::Expression
		{
			pgs::meta::CategoryCPtr _metaCategory;
		public:
			Category();
			Category(pgs::meta::CategoryCPtr cat);

			pgs::meta::CategoryCPtr meta() const;
		};
	}
}

#endif
