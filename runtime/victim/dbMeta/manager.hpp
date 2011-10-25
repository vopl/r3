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
		//объекты из кучи
		SchemaPtrs			_schemas;
		CategoryPtrs		_categories;
		RelationPtrs		_relations;
		RelationEndPtrs		_relationEnds;
		FieldPtrs			_fields;
		IndexPtrs			_indices;

		bool _isStartedUp;

	public:
		//добавить одну категорию по типу
		template <class Schema> void add();

		//после добавления нескольких типизированных необходима эта процедура
		void startup();

		//сериализация, стартапов никаких не нужно
		void serialize();
	};

	///
	template <class T>
	void Manager::add()
	{
		return;
	}

}

#endif
