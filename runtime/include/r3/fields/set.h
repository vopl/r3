#ifndef _R3_FIELDS_SET_H
#define _R3_FIELDS_SET_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Set
	//*******************************************************************

	template <class Domain>
	class Set
		: public Scanty<Domain>
	{
		boost::int32_t _value;
	public:
		boost::int32_t &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
