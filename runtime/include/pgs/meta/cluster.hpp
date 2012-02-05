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
		class ClusterImpl;
		typedef boost::shared_ptr<ClusterImpl> ClusterImplPtr;

		//////////////////////////////////////////////////////////////////////////
		class PG_API Cluster
		{
		protected:
			typedef ClusterImplPtr ImplPtr;
			ImplPtr	_impl;
			void add(boost::shared_ptr<Schema> schema, boost::shared_ptr<SchemaInitializerBase> schemaInitializer);

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

		//////////////////////////////////////////////////////////////////////////
		template <class Schema>
		void Cluster::add()
		{
			boost::shared_ptr<Schema> schema(new Schema);
			boost::shared_ptr<SchemaInitializerBase> schemaInitializer(new SchemaInitializer<Schema>(schema.get()));

			return add(schema, schemaInitializer);
		}

		//////////////////////////////////////////////////////////////////////////
		template <class Schema> 
		const Schema* Cluster::get() const
		{
			return static_cast<const Schema*>(getByName(SchemaInitializer<Schema>::getName()));
		}

	}
}

#endif
