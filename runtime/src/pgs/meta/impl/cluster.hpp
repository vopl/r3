#ifndef _PGS_META_IMPL_CLUSTER_HPP_
#define _PGS_META_IMPL_CLUSTER_HPP_

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
		namespace impl
		{
			//////////////////////////////////////////////////////////////////////////
			class Cluster
				: public boost::enable_shared_from_this<Cluster>
				, private ClusterStorage
			{
				//��������������
				typedef std::vector<boost::shared_ptr<SchemaInitializerBase> > TVSchemaInitializers;
				TVSchemaInitializers _schemaInitializers;
				bool _isInitialized;

				bool doInheritance();
				bool collectInheritance(CategoryPtrs &res, CategoryPtr c, bool bases);

			public:
				Cluster();

				//�������� ���� ��������� �� ����
				void add(boost::shared_ptr<Schema> schema, boost::shared_ptr<SchemaInitializerBase> schemaInitializer);

				//����� ���������� ���������� �������������� ���������� ��� ���������
				void initialize();
				bool isInitialized() const;


				SchemaCPtr getByName(const std::string &name) const;
				const SchemaPtrs &getSchemas() const;
			};
		}
	}
}

#endif
