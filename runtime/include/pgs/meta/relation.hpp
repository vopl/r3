#ifndef _PGS_META_RELATION_HPP_
#define _PGS_META_RELATION_HPP_

#include "pgs/meta/common.hpp"
#include "pgs/meta/relationEnd.hpp"

namespace pgs
{
	namespace meta
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
}

#endif
