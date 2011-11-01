#ifndef _DBWORKER_CATEGORY_HPP_
#define _DBWORKER_CATEGORY_HPP_

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	class Category
	{
		dbMeta::CategoryCPtr _metaCategory;
	public:
		Category();
		Category(dbMeta::CategoryCPtr cat);

		dbMeta::CategoryCPtr meta() const;
	};
}

#endif
