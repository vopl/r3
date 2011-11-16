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

			//наименование
			std::string		_name;

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
