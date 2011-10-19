#ifndef _DBMETA_SCHEMA_HPP_
#define _DBMETA_SCHEMA_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	
	//////////////////////////////////////////////////////////////////////////
	class Schema
	{
	protected:
		Schema(
			ManagerPtr manager,
			const std::string _name,
			const CategoryPtrs _categories,
			const RelationPtrs _relations);

	public:
		const std::string	_name;
		const CategoryPtrs	_categories;
		const RelationPtrs	_relations;


		const RelationPtr getRelation(const std::string &name);
	};
}

#endif
