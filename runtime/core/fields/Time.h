#ifndef _R3_FIELD_TIME_H
#define _R3_FIELD_TIME_H

#include "./Field.h"


namespace r3
{
	//*******************************************************************
	//   C  L  A  S  S   Time
	//*******************************************************************
	template <bool allowNull = true>
	class Time
		: public DateTimeValue<allowNull>
	{
	public:
	}; // class
}  // namespace


#endif
