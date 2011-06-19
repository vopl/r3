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
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

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

		Real64 &operator=(boost::int8_t from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Real64 &operator=(boost::int16_t from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Real64 &operator=(boost::int32_t from)
		{
			fvs(fvs_set);
			_value = (float)from;
			return *this;
		}
		Real64 &operator=(boost::int64_t from)
		{
			fvs(fvs_set);
			_value = (float)from;
			return *this;
		}

		Real64 &operator=(float from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Real64 &operator=(double from)
		{
			fvs(fvs_set);
			_value = (float)from;
			return *this;
		}

		bool operator==(float with) const
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}

		bool operator==(double with) const
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}

		bool operator==(EFieldValueState fvs) const
		{
			return Field::operator ==(fvs);
		}

	}; // class
}}  // namespace


#endif
