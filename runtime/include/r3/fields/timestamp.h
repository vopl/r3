#ifndef _R3_FIELDS_TIMESTAMP_H
#define _R3_FIELDS_TIMESTAMP_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Timestamp
	//*******************************************************************

	class Timestamp
		: public DateTimeValue
	{
	public:
		typedef boost::posix_time::ptime TValue;
	private:
		boost::posix_time::ptime _value;
	public:
		boost::posix_time::ptime &value()
		{
			return _value;
		}

		Timestamp &operator=(const TValue &from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}

		bool operator==(const TValue &with)
		{
			if(fvs() != fvs_set)
			{
				return false;
			}

			return _value == with;
		}
		bool operator==(EFieldValueState fvs)
		{
			return Field::operator ==(fvs);
		}
	}; // class
}}  // namespace


#endif
