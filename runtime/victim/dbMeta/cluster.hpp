#ifndef _DBMETA_CLUSTER_HPP_
#define _DBMETA_CLUSTER_HPP_

#include "dbMeta/clusterStorage.hpp"
#include "dbMeta/schemaInitializer.hpp"
#include "dbMeta/schema.hpp"
#include "dbMeta/field.hpp"
#include "dbMeta/index.hpp"
#include "dbMeta/category.hpp"

namespace dbMeta
{

	//////////////////////////////////////////////////////////////////////////
	class Cluster
		: private ClusterStorage
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
		template <class Schema> void add();

		//����� ���������� ���������� �������������� ���������� ��� ���������
		void initialize();

		template <class Schema> const Schema* get();
		SchemaCPtr getByName(const std::string &name);

		//������������, ��������� ������� �� �����
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
	const Schema* Cluster::get()
	{
		return static_cast<Schema*>(_schemas[SchemaInitializer<Schema>::getName()]);
	}

}

#endif
