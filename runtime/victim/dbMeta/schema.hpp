#ifndef _DBMETA_SCHEMA_HPP_
#define _DBMETA_SCHEMA_HPP_

namespace dbMeta
{
	class Manager;

	class Category;
	typedef Category * CategoryPtr;
	typedef std::vector<CategoryPtr> CategoryPtrs;

	class Schema
	{
		friend class Manager;
		virtual void init(const Manager *man);
		virtual void init() =0;

		typedef std::map<std::string, CategoryPtr> TMCategories;
		TMCategories _mcategories;
	public:
		virtual std::string getName() const=0;

		virtual const std::vector<CategoryPtr> &getCategories() const=0;
		const CategoryPtr getCategory(const std::string &name) const;
	};

	typedef Schema * SchemaPtr;
	typedef std::vector<SchemaPtr> SchemaPtrs;

}

#endif
