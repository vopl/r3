#ifndef _DBMETA_SCHEMA_HPP_
#define _DBMETA_SCHEMA_HPP_

namespace dbMeta
{
	class Manager;

	class Category;
	typedef Category * CategoryPtr;

	class Schema
	{
		friend class Manager;
		virtual void init(const Manager *man);
		virtual void init() =0;

		std::map<std::string, CategoryPtr> _mcategories;
	public:
		virtual const std::vector<CategoryPtr> &getCategories() const;
		const CategoryPtr getCategory(const std::string &name) const;
	};

	typedef Schema * SchemaPtr;
	typedef std::set<SchemaPtr> SchemaPtrs;

}

#endif
