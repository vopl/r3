#ifndef _DBMETA_INDEX_HPP_
#define _DBMETA_INDEX_HPP_

namespace dbMeta
{
	enum EIndexType
	{
		eitTree,
		eitHash,
	};

	class Category;
	typedef Category *CategoryPtr;

	class Index
	{
	public:
		const CategoryPtr getCategory() const;

	};

	typedef Index * IndexPtr;
	typedef std::set<IndexPtr> IndexPtrs;

}

#endif
