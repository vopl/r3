#ifndef _R3_FIELDS_REAL64_H
#define _R3_FIELDS_REAL64_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Real64
	//*******************************************************************

	class Real64
		: public Real
	{
	public:
		typedef double TValue;
	private:
		double _value;
	public:
		Real64()
			: _value(0)
		{

		}
		double &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
