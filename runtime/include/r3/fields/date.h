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
	public:
		typedef boost::gregorian::date TValue;
	private:
		boost::gregorian::date _value;
	public:
		Date();
		Date(const boost::gregorian::date &from);

		boost::gregorian::date &value();
		const boost::gregorian::date &value() const;

		Date &operator=(const boost::gregorian::date &from);

		operator boost::gregorian::date ()const;

	}; // class
}}  // namespace


#endif
