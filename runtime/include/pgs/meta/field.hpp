#ifndef _PGS_META_FIELD_HPP_
#define _PGS_META_FIELD_HPP_

#include "pgs/meta/common.hpp"

namespace pgs
{
	namespace meta
	{
		enum EFieldType
		{
			eftAudio,
			eftBinary,
			eftBool,
			eftDate,
			eftDateTimeInterval,
			eftEnum,
			eftFile,
			eftId,
			eftImage,
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
			eftVideo,
		};

		//////////////////////////////////////////////////////////////////////////
		class Field
		{
		public:

			//������������
			std::string		_name;

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
