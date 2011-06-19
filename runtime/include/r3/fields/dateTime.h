#ifndef _R3_FIELDS_DATETIME_H
#define _R3_FIELDS_DATETIME_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   DateTime
	//*******************************************************************

	class DateTime
		: public Simple
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
	}; // class
}}  // namespace


#endif
