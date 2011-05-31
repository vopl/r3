#ifndef _R3_FIELDS_INT8_H
#define _R3_FIELDS_INT8_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Int8
	//*******************************************************************

	class Int8
		: public Int
	{
		boost::int8_t _value;
	public:
		boost::int8_t &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
