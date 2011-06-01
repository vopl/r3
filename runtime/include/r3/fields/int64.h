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
	public:
		typedef boost::int64_t TValue;
	private:
		boost::int64_t _value;
	public:
		Int64()
			: _value(0)
		{

		}

		boost::int64_t &value()
		{
			return _value;
		}
		const boost::int64_t &value() const 
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
