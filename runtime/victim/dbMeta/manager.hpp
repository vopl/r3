#ifndef _DBMETA_MANAGER_HPP_
#define _DBMETA_MANAGER_HPP_

#include "dbMeta/field.hpp"
#include "dbMeta/index.hpp"
#include "dbMeta/category.hpp"
#include "dbMeta/schema.hpp"

namespace dbMeta
{
	class Manager
	{
		//������� �� ����
		SchemaPtrs			_schemas;
		CategoryPtrs		_categories;
		RelationPtrs		_relations;
		RelationEndPtrs		_relationEnds;
		FieldPtrs			_fields;
		IndexPtrs			_indices;

		bool _isStartedUp;

	public:
		//�������� ���� ��������� �� ����
		template <class Schema> void add();

		//����� ���������� ���������� �������������� ���������� ��� ���������
		void startup();

		//������������, ��������� ������� �� �����
		void serialize();
	};

	///
	template <class T>
	void Manager::add()
	{
		return;
	}

}

#endif
