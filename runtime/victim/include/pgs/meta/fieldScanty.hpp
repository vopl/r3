#ifndef _PGS_META_FIELDSCANTY_HPP_
#define _PGS_META_FIELDSCANTY_HPP_

#include "pgs/meta/field.hpp"

namespace pgs
{
	namespace meta
	{
		//////////////////////////////////////////////////////////////////////////
		//set, enum
		class FieldScantyValue
		{
		public:
			std::string		_name;
			int				_key;
			std::string		_shortDescription;
			std::string		_longDescription;
			FieldScantyPtr	_field;
		};

		//////////////////////////////////////////////////////////////////////////
		//set, enum
		class FieldScanty
			: public Field
		{
		public:
			//значения
			FieldScantyValuePtrs _values;
		};

	}
}

#endif
