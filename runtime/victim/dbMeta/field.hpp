#ifndef _DBMETA_FIELD_HPP_
#define _DBMETA_FIELD_HPP_

namespace dbMeta
{

	class Category;
	typedef Category *CategoryPtr;

	class Field
	{
	public:
		const CategoryPtr getCategory() const;
	};

	typedef Field * FieldPtr;
	typedef std::set<FieldPtr> FieldPtrs;
}

#endif
