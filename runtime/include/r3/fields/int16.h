#ifndef _R3_FIELDS_INT16_H
#define _R3_FIELDS_INT16_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Int16
	//*******************************************************************

	class Int16
		: public Int<boost::int16_t>
	{
	public:

		Int16 &operator=(boost::int8_t from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Int16 &operator=(boost::int16_t from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Int16 &operator=(boost::int32_t from)
		{
			fvs(fvs_set);
			_value = (boost::int16_t)from;
			return *this;
		}
		Int16 &operator=(boost::int64_t from)
		{
			fvs(fvs_set);
			_value = (boost::int16_t)from;
			return *this;
		}

	}; // class
}}  // namespace


#endif
