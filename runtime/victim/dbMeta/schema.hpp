#ifndef _DBMETA_SCHEMA_HPP_
#define _DBMETA_SCHEMA_HPP_

namespace dbMeta
{
	class Schema
	{
	public:
		const CategoryPtr getCategory(const std::string &name) const;
	};

	typedef Schema * SchemaPtr;
	typedef std::set<SchemaPtr> SchemaPtrs;

}

#endif
