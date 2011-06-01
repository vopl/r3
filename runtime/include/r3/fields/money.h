#ifndef _R3_FIELDS_MONEY_H
#define _R3_FIELDS_MONEY_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Money
	//*******************************************************************

	class Money
		: public Simple
	{
		pgc::Money _value;
	public:
		Money();
		Money(const boost::int64_t &from);

		pgc::Money &value();
		const pgc::Money &value() const;

		Money &operator=(const boost::int32_t &from);
		Money &operator=(const boost::int64_t &from);
		Money &operator=(float from);
		Money &operator=(double from);
	}; // class
}}  // namespace


#endif
