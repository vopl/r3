#ifndef _DBWORKER_CATEGORY_HPP_
#define _DBWORKER_CATEGORY_HPP_

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	class Category
	{
		dbMeta::CategoryCPtr _metaCategory;
	public:
		Category(dbMeta::CategoryCPtr cat);
	};
}

#endif
