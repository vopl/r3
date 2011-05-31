#ifndef _R3_FIELDS_TIMESTAMP_H
#define _R3_FIELDS_TIMESTAMP_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Timestamp
	//*******************************************************************

	class Timestamp
		: public DateTimeValue
	{
		boost::posix_time::ptime _value;
	public:
		boost::posix_time::ptime &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
