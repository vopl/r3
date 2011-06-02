#ifndef _R3_FIELDS_INT32_H
#define _R3_FIELDS_INT32_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Int32
	//*******************************************************************

	class Int32
		: public Int<boost::int32_t>
	{
	public:
		Int32 &operator=(boost::int8_t from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Int32 &operator=(boost::int16_t from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Int32 &operator=(boost::int32_t from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Int32 &operator=(boost::int64_t from)
		{
			fvs(fvs_set);
			_value = (boost::int32_t)from;
			return *this;
		}

		Int32 &operator=(EFieldValueState from)
		{
			Field::operator =(from);
			return *this;
		}
		bool operator==(EFieldValueState with)
		{
			return Field::operator ==(with);
		}







		bool operator==(boost::int8_t with)
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}
		bool operator==(boost::int16_t with)
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}
		bool operator==(boost::int32_t with)
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}
		bool operator==(boost::int64_t with)
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}

		bool operator==(Int32 with)
		{
			if(!Field::operator ==(with))
			{
				return false;
			}
			return _value == with._value;
		}
	}; // class
}}  // namespace


#endif
