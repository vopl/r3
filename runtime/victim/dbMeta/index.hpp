#ifndef _DBMETA_INDEX_HPP_
#define _DBMETA_INDEX_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	//////////////////////////////////////////////////////////////////////////
	enum EIndexType
	{
		eitTree,
		eitHash,
	};

	//////////////////////////////////////////////////////////////////////////
	class Index
	{
	public:
		//������������
		std::string	_name;

		//��� �������
		EIndexType	_type;

		//��������������� ����
		FieldPtrs	_fields;

		//���������� ���������
		CategoryPtr	_category;
	};
}

#endif
