#ifndef _R3_FIELDS_REAL32_H
#define _R3_FIELDS_REAL32_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Real32
	//*******************************************************************

	class Real32
		: public Real
	{
		float _value;
	public:
		Real32()
			: _value(0)
		{

		}
		float &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
