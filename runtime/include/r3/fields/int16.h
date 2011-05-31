#ifndef _R3_FIELDS_INT16_H
#define _R3_FIELDS_INT16_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Int16
	//*******************************************************************

	class Int16
		: public Int
	{
		boost::int16_t _value;
	public:
		boost::int16_t &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
