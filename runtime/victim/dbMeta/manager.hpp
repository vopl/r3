#ifndef _DBMETA_MANAGER_HPP_
#define _DBMETA_MANAGER_HPP_

#include "dbMeta/managerStorage.hpp"
#include "dbMeta/schemaInitializer.hpp"

namespace dbMeta
{

	//////////////////////////////////////////////////////////////////////////
	class Manager
		: private ManagerStorage
	{
		//��������������
		typedef std::vector<boost::shared_ptr<SchemaInitializerBase> > TVSchemaInitializers;
		TVSchemaInitializers _schemaInitializers;
		bool _isInitialized;

		bool doInheritance();
		bool collectInheritance(CategoryPtrs &res, CategoryPtr c, bool bases);

	public:
		Manager();

		//�������� ���� ��������� �� ����
		template <class Schema> void add();

		//����� ���������� ���������� �������������� ���������� ��� ���������
		void initialize();

		//������������, ��������� ������� �� �����
		//void serialize();
	};

	///
	template <class Schema>
	void Manager::add()
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

}

#endif
