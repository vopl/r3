#ifndef _R3_FIELDS_DATETIMEVALUE_H
#define _R3_FIELDS_DATETIMEVALUE_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   DateTimeValue
	//*******************************************************************

	class DateTimeValue
		: public DateTime
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
	}; // class
}}  // namespace


#endif
