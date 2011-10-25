#ifndef _DBMETA_MANAGERSTORAGE_HPP_
#define _DBMETA_MANAGERSTORAGE_HPP_

#include "dbMeta/field.hpp"
#include "dbMeta/index.hpp"
#include "dbMeta/category.hpp"
#include "dbMeta/schema.hpp"
#include "dbMeta/schemaInitializer.hpp"

#include <boost/shared_ptr.hpp>
namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	class ManagerStorage
	{
	public:
		//объекты из кучи
		std::vector<boost::shared_ptr<Schema> >				_schemas_heap;
		std::vector<boost::shared_ptr<Category> >			_categories_heap;
		std::vector<boost::shared_ptr<Relation> >			_relations_heap;
		std::vector<boost::shared_ptr<RelationEnd> >		_relationEnds_heap;
		std::vector<boost::shared_ptr<Field> >				_fields_heap;
		std::vector<boost::shared_ptr<FieldScantyValue> >	_fieldScantyValues_heap;
		std::vector<boost::shared_ptr<Index> >				_indices_heap;

		//точка входа для схем после инициализации
		SchemaPtrs _schemas;
	};
}

#endif
