#ifndef _R3_FIELDS_TIME_H
#define _R3_FIELDS_TIME_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Time
	//*******************************************************************

	class Time
		: public DateTimeValue
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
		typedef boost::posix_time::time_duration TValue;

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

		Time &operator=(EFieldValueState from)
		{
			Field::operator =(from);
			return *this;
		}
		bool operator==(EFieldValueState with)
		{
			return Field::operator ==(with);
		}



		bool operator==(TValue with)
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}

		bool operator==(Time with)
		{
			if(!Field::operator ==(with))
			{
				return false;
			}
			return _value == with._value;
		}

		Time &operator=(const TValue &from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}

		Time &operator=(const Time &from)
		{
			Field::operator =(from);
			_value = from._value;
			return *this;
		}

	}; // class
}}  // namespace


#endif
