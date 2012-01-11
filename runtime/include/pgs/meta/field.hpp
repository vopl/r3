#ifndef _PGS_META_FIELD_HPP_
#define _PGS_META_FIELD_HPP_

#include "pgs/meta/common.hpp"

namespace pgs
{
	namespace meta
	{
		enum EFieldType
		{
			eftBinary,
			eftBool,
			eftDate,
			eftDateTimeInterval,
			eftEnum,
			eftFile,
			eftId,
			eftInt16,
			eftInt32,
			eftInt64,
			eftInt8,
			eftMoney,
			eftReal32,
			eftReal64,
			eftSet,
			eftString,
			eftTime,
			eftTimestamp,
			eftUuid,
			eftVariant,
			eftBitset8,
			eftBitset16,
			eftBitset32,
			eftBitset64,
			eftBitset128,
			eftBitset256,
			eftBitset512,
		};

		//////////////////////////////////////////////////////////////////////////
		class Field
		{
		public:

			//������������
			std::string		_name;

			//����������� ������� ��������
			bool			_allowNull;

			//��� ����
			EFieldType		_type;

			//������� �������� ���������, � ������� ������������� ��� ����
			IndexPtrs		_indices;

			//�������� ���������, � ������� ��������� ��� ����
			CategoryPtr		_category;
			CategoryPtrs	_categories;
		};
	}
}

#endif
