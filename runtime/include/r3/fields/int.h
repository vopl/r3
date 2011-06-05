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
	protected:
		TValue _value;
	public:
		Int()
			: Simple()
			, _value()
		{
		}

		template <class I2>
		Int(const Int<I2> &v)
			: Simple(v)
			, _value(v._value)
		{
		}

		Int(const Integral &v)
			: Simple(v)
			, _value(v._value)
		{
		}

		TValue &value()
		{
			return _value;
		}
		const TValue &value() const 
		{
			return _value;
		}

		template <class I2>
		void operator=(const Int<I2> &v) const
		{
			Simple::operator =(v);
			_value = v._value;
		}

		template <class I2>
		bool operator==(const Int<I2> &v) const
		{
			if(!Simple::operator==(v))
			{
				return false;
			}
			return _value == v._value;
		}
		template <class I2>
		bool operator!=(const Int<I2> &v) const
		{
			return !operator==(v);
		}

		void operator=(const Integral &v)
		{
			fvs(fvs_set);
			_value = v;
		}
		bool operator==(const Integral &v) const
		{
			if(fvs()!=fvs_set)
			{
				return false;
			}
			return _value == v;
		}
		template <class I2>
		bool operator!=(const Integral &v) const
		{
			return !operator==(v);
		}

		using Simple::operator==;
		using Simple::operator!=;

	}; // class
}}  // namespace


#endif
