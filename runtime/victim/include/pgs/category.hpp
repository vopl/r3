#ifndef _PGS_CATEGORY_HPP_
#define _PGS_CATEGORY_HPP_

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class Category
	{
		pgs::meta::CategoryCPtr _metaCategory;
	public:
		Category();
		Category(pgs::meta::CategoryCPtr cat);

		pgs::meta::CategoryCPtr meta() const;
	};
}

#endif
