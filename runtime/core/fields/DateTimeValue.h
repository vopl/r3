#ifndef _R3_FIELD_DATETIMEVALUE_H
#define _R3_FIELD_DATETIMEVALUE_H

#include "./Field.h"


namespace r3
{
	//*******************************************************************
	//   C  L  A  S  S   DateTimeValue
	//*******************************************************************
	template <bool allowNull = true>
	class DateTimeValue
		: public DateTime<allowNull>
	{
	public:
	}; // class
}  // namespace


#endif
