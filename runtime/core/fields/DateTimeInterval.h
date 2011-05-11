#ifndef _R3_FIELD_DATETIMEINTERVAL_H
#define _R3_FIELD_DATETIMEINTERVAL_H

#include "./Field.h"


namespace r3
{
	//*******************************************************************
	//   C  L  A  S  S   DateTimeInterval
	//*******************************************************************
	template <bool allowNull = true>
	class DateTimeInterval
		: public DateTime<allowNull>
	{
	public:
	}; // class
}  // namespace


#endif
