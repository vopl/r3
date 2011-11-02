#ifndef _DBMETA_SCHEMA_HPP_
#define _DBMETA_SCHEMA_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	
	//////////////////////////////////////////////////////////////////////////
	class Schema
	{
	public:
		//наименование
		std::string			_name;

		//все категории
		CategoryPtrs		_categories;

		//все связи
		RelationPtrs		_relations;

		//объемлющий менеджер
		ClusterStoragePtr	_storage;
	};
}

#endif
