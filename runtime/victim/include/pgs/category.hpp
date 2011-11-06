#ifndef _PGS_CATEGORY_HPP_
#define _PGS_CATEGORY_HPP_

#include "pgs/expression.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class Category
		: public Expression
	{
		pgs::meta::CategoryCPtr _metaCategory;
	public:
		Category();
		Category(pgs::meta::CategoryCPtr cat);

		pgs::meta::CategoryCPtr meta() const;
	};
}

#endif
