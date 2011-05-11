#ifndef _R3_FIELD_TIMESTAMP_H
#define _R3_FIELD_TIMESTAMP_H

#include "./Field.h"


namespace r3
{
	//*******************************************************************
	//   C  L  A  S  S   Timestamp
	//*******************************************************************
	template <bool allowNull = true>
	class Timestamp
		: public DateTimeValue<allowNull>
	{
	public:
	}; // class
}  // namespace


#endif
