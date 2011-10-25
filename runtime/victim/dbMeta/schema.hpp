#ifndef _DBMETA_SCHEMA_HPP_
#define _DBMETA_SCHEMA_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	
	//////////////////////////////////////////////////////////////////////////
	class Schema
	{
	public:
		//������������
		std::string		_name;

		//��� ���������
		CategoryPtrs	_categories;

		//��� �����
		RelationPtrs	_relations;

		//���������� ��������
		ManagerStoragePtr		_storage;
	};
}

#endif
