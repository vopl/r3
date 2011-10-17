#ifndef _DBMETA_MANAGER_HPP_
#define _DBMETA_MANAGER_HPP_

#include "dbMeta/field.hpp"
#include "dbMeta/index.hpp"
#include "dbMeta/category.hpp"
#include "dbMeta/schema.hpp"

namespace dbMeta
{
	class Manager
	{
	public:
		template <class Schema>
		void add();

		const SchemaPtr getSchema(const std::string &name) const;
	};
}

#endif
