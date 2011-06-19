#ifndef _R3_FIELDS_REAL_H
#define _R3_FIELDS_REAL_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Real
	//*******************************************************************

	class Real
		: public Simple
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
	}; // class
}}  // namespace


#endif
