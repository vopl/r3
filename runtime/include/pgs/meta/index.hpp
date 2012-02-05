#ifndef _PGS_META_INDEX_HPP_
#define _PGS_META_INDEX_HPP_

#include "pgs/meta/common.hpp"

namespace pgs
{
	namespace meta
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
			std::string		_name;

			//��� �������
			EIndexType		_type;

			//��������������� ����
			FieldPtrs		_fields;

			//���������� ���������
			CategoryPtr		_category;
			CategoryPtrs	_categories;
		};
	}
}

#endif
