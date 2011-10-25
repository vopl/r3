#ifndef _DBMETA_MANAGER_HPP_
#define _DBMETA_MANAGER_HPP_

#include "dbMeta/field.hpp"
#include "dbMeta/index.hpp"
#include "dbMeta/category.hpp"
#include "dbMeta/schema.hpp"
#include "dbMeta/schemaInitializer.hpp"

#include <boost/shared_ptr.hpp>
namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	class Manager
	{
		//объекты из кучи
		PtrContainer<boost::shared_ptr<Schema>, boost::shared_ptr<const Schema> >			_schemas;
		PtrContainer<boost::shared_ptr<Category>, boost::shared_ptr<const Category> >		_categories;
		PtrContainer<boost::shared_ptr<Relation>, boost::shared_ptr<const Relation> >		_relations;
		PtrContainer<boost::shared_ptr<RelationEnd>, boost::shared_ptr<const RelationEnd> >	_relationEnds;
		PtrContainer<boost::shared_ptr<Field>, boost::shared_ptr<const Field> >				_fields;
		PtrContainer<boost::shared_ptr<Index>, boost::shared_ptr<const Index> >				_indices;

		//
		typedef std::vector<boost::shared_ptr<SchemaInitializerBase> > TVSchemaInitializers;
		TVSchemaInitializers _schemaInitializers;

		bool _isInitialized;

	public:
		//добавить одну категорию по типу
		template <class Schema> void add();

		//после добавления нескольких типизированных необходима эта процедура
		void initialize();

		//сериализация, стартапов никаких не нужно
		//void serialize();
	};

	///
	template <class Schema>
	void Manager::add()
	{
		boost::shared_ptr<Schema> schema(new Schema);
		boost::shared_ptr<SchemaInitializerBase> schemaInitializer(new SchemaInitializer<Schema>(this, schema.get()));

		_schemas.push_back(schema);
		_schemaInitializers.push_back(schemaInitializer);

		return;
	}

}

#endif
