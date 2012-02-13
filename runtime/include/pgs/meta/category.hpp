#ifndef _PGS_META_CATEGORY_HPP_
#define _PGS_META_CATEGORY_HPP_

#include "pgs/meta/common.hpp"

namespace pgs
{
	namespace meta
	{
		class Category
		{
		public:
			//наименование
			std::string		_name;
			//признак абстрактности, в абстрактные недльзя писать
			bool			_isAbstract;

			//поля без наследования
			FieldPtrs		_ownFields;
			//индексы без наследования
			IndexPtrs		_ownIndices;
			//связи без наследования
			RelationEndPtrs	_ownRelationEnds;

			//поля с наследованием
			FieldPtrs		_fields;
			//индексы с наследованием
			IndexPtrs		_indices;
			//связи с наследованием
			RelationEndPtrs	_relationEnds;

			//базовые категории первого уровня
			CategoryPtrs	_bases;
			//базовые категории все
			CategoryPtrs	_allBases;

			//производные категории первого уровня
			CategoryPtrs	_deriveds;
			//производные категории все
			CategoryPtrs	_allDeriveds;

			//объемлющая схема
			SchemaPtr		_schema;
		};
	}
}

#endif
