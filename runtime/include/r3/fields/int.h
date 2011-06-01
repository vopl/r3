#ifndef _R3_FIELDS_INT_H
#define _R3_FIELDS_INT_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Int
	//*******************************************************************

	template <class Integral>
	class Int
		: public Simple
	{
	public:
		typedef Integral TValue;
	private:
		TValue _value;
	public:
		TValue &value()
		{
			return _value;
		}
		const TValue &value() const 
		{
			return _value;
		}

		template <class I2>
		Field &operator=(const Int<I2> &from) const
		{
			Simple::operator =(from);
			_value = from._value;
			return *this;
		}

		template <class I2>
		bool operator==(const Int<I2> &with) const
		{
			if(!Simple::operator==(with))
			{
				return false;
			}
			return _value == with._value;
		}

		Field &operator=(Integral from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		bool operator==(const Integral &with) const
		{
			if(fvs()!=fvs_set)
			{
				return false;
			}
			return _value == with;
		}

	}; // class
}}  // namespace


#endif
