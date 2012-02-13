#ifndef _PGS_META_SCHEMA_HPP_
#define _PGS_META_SCHEMA_HPP_

#include "pgs/meta/common.hpp"

namespace pgs
{
	namespace meta
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
}

#endif
