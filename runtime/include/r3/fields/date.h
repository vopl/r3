#ifndef _R3_FIELDS_DATE_H
#define _R3_FIELDS_DATE_H

#include "r3/fields/field.h"

namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Date
	//*******************************************************************

	class Date
		: public DateTimeValue
	{
		boost::gregorian::date _value;
	public:
		const boost::gregorian::date &value() const;
		boost::gregorian::date &value();

	}; // class
}}  // namespace


#endif
