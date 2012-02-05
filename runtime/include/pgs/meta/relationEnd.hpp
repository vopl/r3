#ifndef _PGS_META_RELATIONEND_HPP_
#define _PGS_META_RELATIONEND_HPP_

#include "pgs/meta/common.hpp"

namespace pgs
{
	namespace meta
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

			//������� ������� �����
			bool			_isInput;

			//���������
			ERelationMult	_mult;

			//��������� ���������
			CategoryPtr		_category;
			CategoryPtrs	_categories;

			//������ ����
			RelationEndPtr	_anotherEnd;

			//���������� �����
			RelationPtr		_relation;

		};
	}
}

#endif
