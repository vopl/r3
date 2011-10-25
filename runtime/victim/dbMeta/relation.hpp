#ifndef _DBMETA_RELATION_HPP_
#define _DBMETA_RELATION_HPP_

#include "dbMeta/common.hpp"
#include "dbMeta/relationEnd.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	class Relation
	{
	public:
		//������������
		std::string		_name;

		//�������� ����
		RelationEnd		inputEnd;

		//��������� ����
		RelationEnd		outputEnd;

		//���������� �����
		SchemaPtr		_schema;
	};
}

#endif
