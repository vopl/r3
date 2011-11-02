#ifndef _PGS_META_SCHEMA_HPP_
#define _PGS_META_SCHEMA_HPP_

#include "pgs/meta/common.hpp"

namespace pgs
{
	namespace meta
	{
		
		//////////////////////////////////////////////////////////////////////////
		class Schema
		{
		public:
			//������������
			std::string			_name;

			//��� ���������
			CategoryPtrs		_categories;

			//��� �����
			RelationPtrs		_relations;

			//���������� ��������
			ClusterStoragePtr	_storage;
		};
	}
}

#endif
