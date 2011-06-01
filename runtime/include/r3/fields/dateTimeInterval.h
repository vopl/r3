#ifndef _R3_FIELDS_DATETIMEINTERVAL_H
#define _R3_FIELDS_DATETIMEINTERVAL_H

#include "r3/fields/field.h"
#include "pgc/cppDataType.hpp"

namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   DateTimeInterval
	//*******************************************************************

	class DateTimeInterval
		: public DateTime
	{
	public:
		typedef pgc::DateTimeDuration TValue;
	private:
		pgc::DateTimeDuration _value;
	public:
		pgc::DateTimeDuration &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
