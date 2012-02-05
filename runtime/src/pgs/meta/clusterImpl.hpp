#ifndef _PGS_META_CLUSTERIMPL__HPP_
#define _PGS_META_CLUSTERIMPL__HPP_

#include <boost/enable_shared_from_this.hpp>

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
		class ClusterImpl
			: public boost::enable_shared_from_this<ClusterImpl>
			, private ClusterStorage
		{
			//инициализаторы
			typedef std::vector<boost::shared_ptr<SchemaInitializerBase> > TVSchemaInitializers;
			TVSchemaInitializers _schemaInitializers;
			bool _isInitialized;

			bool doInheritance();
			bool collectInheritance(CategoryPtrs &res, CategoryPtr c, bool bases);

		public:
			ClusterImpl();

			//добавить одну категорию по типу
			void add(boost::shared_ptr<Schema> schema, boost::shared_ptr<SchemaInitializerBase> schemaInitializer);

			//после добавления нескольких типизированных необходима эта процедура
			void initialize();
			bool isInitialized() const;


			SchemaCPtr getByName(const std::string &name) const;
			const SchemaPtrs &getSchemas() const;
		};
	}
}

#endif
