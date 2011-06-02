#ifndef _R3_FIELDS_ID_H
#define _R3_FIELDS_ID_H

#include "r3/fields/field.h"

namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Id
	//*******************************************************************

	class Id
		: public Int64
	{
	public:
		bool operator==(const EFieldValueState with) const
		{
			return Field::operator ==(with);
		}

		bool operator==(Id with)
		{
			if(!Field::operator ==(with))
			{
				return false;
			}
			return _value == with._value;
		}

	}; // class
}}  // namespace


#endif
