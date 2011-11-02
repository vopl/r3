#ifndef _PGS_META_CLUSTER_HPP_
#define _PGS_META_CLUSTER_HPP_

#include "pgs/meta/clusterStorage.hpp"
#include "pgs/meta/schemaInitializer.hpp"
#include "pgs/meta/schema.hpp"
#include "pgs/meta/field.hpp"
#include "pgs/meta/index.hpp"
#include "pgs/meta/category.hpp"
#include "pgs/meta/relation.hpp"
#include "pgs/meta/relationEnd.hpp"

namespace pgs
{
	namespace meta
	{

		//////////////////////////////////////////////////////////////////////////
		class Cluster
			: private ClusterStorage
		{
			//инициализаторы
			typedef std::vector<boost::shared_ptr<SchemaInitializerBase> > TVSchemaInitializers;
			TVSchemaInitializers _schemaInitializers;
			bool _isInitialized;

			bool doInheritance();
			bool collectInheritance(CategoryPtrs &res, CategoryPtr c, bool bases);

		public:
			Cluster();

			//добавить одну категорию по типу
			template <class Schema> void add();

			//после добавления нескольких типизированных необходима эта процедура
			void initialize();
			bool isInitialized() const;


			template <class Schema> const Schema* get() const;
			SchemaCPtr getByName(const std::string &name) const;
			const SchemaPtrs &getSchemas() const;

			//сериализация, стартапов никаких не нужно
			//void serialize();
		};

		///
		template <class Schema>
		void Cluster::add()
		{
			if(_isInitialized)
			{
				assert(!"already initialized");
				throw "already initialized";
				return;
			}

			boost::shared_ptr<Schema> schema(new Schema);
			boost::shared_ptr<SchemaInitializerBase> schemaInitializer(new SchemaInitializer<Schema>(this, schema.get()));

			_schemaInitializers.push_back(schemaInitializer);
			_schemas_heap.push_back(schema);

			return;
		}

		//////////////////////////////////////////////////////////////////////////
		template <class Schema> 
		const Schema* Cluster::get() const
		{
			return static_cast<const Schema*>(_schemas[SchemaInitializer<Schema>::getName()]);
		}

	}
}

#endif
