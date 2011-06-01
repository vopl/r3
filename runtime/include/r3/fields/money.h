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
		pgc::Money &value()
		{
			return _value;
		}

		Money &operator=(const boost::uint64_t &val)
		{
			_value._value = val;
		}
	}; // class
}}  // namespace


#endif
