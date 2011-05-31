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
		boost::uint64_t _value;
	public:
		boost::uint64_t &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
