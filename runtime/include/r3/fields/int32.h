#ifndef _R3_FIELDS_INT32_H
#define _R3_FIELDS_INT32_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Int32
	//*******************************************************************

	class Int32
		: public Int
	{
	public:
		typedef boost::int32_t TValue;
	private:
		boost::int32_t _value;
	public:
		Int32()
			: _value(0)
		{

		}
		boost::int32_t &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
