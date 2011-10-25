#ifndef _DBMETA_CATEGORY_HPP_
#define _DBMETA_CATEGORY_HPP_

#include "dbMeta/common.hpp"

namespace dbMeta
{
	class Category
	{
	public:
		//������������
		std::string		_name;
		//������� �������������, � ����������� ������� ������
		bool			_isAbstract;

		//���� ��� ������������
		FieldPtrs		_ownFields;
		//������� ��� ������������
		IndexPtrs		_ownIndices;
		//����� ��� ������������
		RelationEndPtrs	_ownRelationEnds;

		//���� � �������������
		FieldPtrs		_fields;
		//������� � �������������
		IndexPtrs		_indices;
		//����� � �������������
		RelationEndPtrs	_relationEnds;

		//������� ��������� ������� ������
		CategoryPtrs	_bases;
		//������� ��������� ���
		CategoryPtrs	_allBases;

		//����������� ��������� ������� ������
		CategoryPtrs	_deriveds;
		//����������� ��������� ���
		CategoryPtrs	_allDeriveds;

		//���������� �����
		SchemaPtr		_schema;
	};
}

#endif
