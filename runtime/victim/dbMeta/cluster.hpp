#ifndef _DBMETA_CLUSTER_HPP_
#define _DBMETA_CLUSTER_HPP_

#include "dbMeta/clusterStorage.hpp"
#include "dbMeta/schemaInitializer.hpp"
#include "dbMeta/schema.hpp"
#include "dbMeta/field.hpp"
#include "dbMeta/index.hpp"
#include "dbMeta/category.hpp"
#include "dbMeta/relation.hpp"
#include "dbMeta/relationEnd.hpp"

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
		bool isInitialized() const;


		template <class Schema> const Schema* get() const;
		SchemaCPtr getByName(const std::string &name) const;
		const SchemaPtrs &getSchemas() const;

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
	const Schema* Cluster::get() const
	{
		return static_cast<const Schema*>(_schemas[SchemaInitializer<Schema>::getName()]);
	}

}

#endif
