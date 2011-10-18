#ifndef _DBMETA_CATEGORY_HPP_
#define _DBMETA_CATEGORY_HPP_

namespace dbMeta
{
	class Schema;
	typedef Schema *SchemaPtr;

	class Field;
	typedef Field *FieldPtr;

	class Index;
	typedef Index *IndexPtr;

	class Category
	{
	public:
		const SchemaPtr getSchema() const;
		std::string getName() const;
		const FieldPtr getField(const std::string &name) const;
		const IndexPtr getIndex(const std::string &name) const;
	};

	typedef Category * CategoryPtr;
	typedef std::set<CategoryPtr> CategoryPtrs;

}

#endif
