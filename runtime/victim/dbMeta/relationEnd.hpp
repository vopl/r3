#ifndef _DBMETA_RELATIONEND_HPP_
#define _DBMETA_RELATIONEND_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	enum ERelationMult
	{
		ermMany,
		ermOne,
	};

	//////////////////////////////////////////////////////////////////////////
	class RelationEnd
	{
	public:
		//������������
		std::string		_name;

		//���������
		ERelationMult	_mult;

		//��������� ���������
		CategoryPtr		_category;
		CategoryPtrs	_categories;

		//���������� �����
		RelationPtr		_relation;

	};
}

#endif
