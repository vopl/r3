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

			//наименование
			std::string		_name;

			//возможность пустого значения
			bool			_allowNull;

			//тип поля
			EFieldType		_type;

			//индексы исходной категории, в которых задействовано это поле
			IndexPtrs		_indices;

			//исходная категория, в которой объявлено это поле
			CategoryPtr		_category;
			CategoryPtrs	_categories;
		};
	}
}

#endif
