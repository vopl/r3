#ifndef _R3_FIELDS_SIMPLE_H
#define _R3_FIELDS_SIMPLE_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Simple
	//*******************************************************************
	class Simple
		: public Field
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	protected:
		Simple();
		Simple(const Simple &v);

	public:

	}; // class
}}  // namespace


#endif
