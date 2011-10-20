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
			const Manager &manager,
			const std::string &name,
			const CategoryPtrs categories,
			const RelationPtrs relations);

	public:
		const Manager &		_manager;
		const std::string	_name;
		const CategoryPtrs	_categories;
		const RelationPtrs	_relations;
	};
}

#endif
