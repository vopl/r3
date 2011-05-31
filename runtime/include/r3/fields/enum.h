#ifndef _R3_FIELDS_ENUM_H
#define _R3_FIELDS_ENUM_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Enum
	//*******************************************************************

	template <class Domain>
	class Enum
		: public Scanty<Domain>
	{
		boost::uint32_t _oid;
	public:
		boost::uint32_t &value()
		{
			return _oid;
		}
	}; // class
}}  // namespace


#endif
