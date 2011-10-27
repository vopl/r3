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
		RelationEndPtr	_inputEnd;

		//��������� ����
		RelationEndPtr	_outputEnd;

		//���������� �����
		SchemaPtr		_schema;
	};
}

#endif
