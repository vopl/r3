#ifndef _R3_FIELDS_INT64_H
#define _R3_FIELDS_INT64_H

#include "r3/fields/field.h"

namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Int64
	//*******************************************************************

	class Int64
		: public Int
	{
		boost::int64_t _value;
	public:
		const boost::int64_t &value() const;
		boost::int64_t &value();
	}; // class
}}  // namespace


#endif
