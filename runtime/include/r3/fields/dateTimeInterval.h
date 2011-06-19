#ifndef _R3_FIELDS_DATETIMEINTERVAL_H
#define _R3_FIELDS_DATETIMEINTERVAL_H

#include "r3/fields/field.h"
#include "pgc/cppDataType.hpp"

namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   DateTimeInterval
	//*******************************************************************

	class DateTimeInterval
		: public DateTime
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
		typedef pgc::DateTimeDuration TValue;
	private:
		pgc::DateTimeDuration _value;
	public:
		pgc::DateTimeDuration &value()
		{
			return _value;
		}

		bool operator==(const TValue &with)
		{
			if(fvs() != fvs_set)
			{
				return false;
			}

			return _value._dd == with._dd && _value._td == with._td;
		}
		bool operator==(EFieldValueState fvs)
		{
			return Field::operator ==(fvs);
		}


		DateTimeInterval &operator=(const TValue &from)
		{
			fvs(fvs_set);
			_value = from;

			return *this;
		}


	}; // class
}}  // namespace


#endif
