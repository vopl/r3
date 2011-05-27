#ifndef _R3_FIELDS_SCANTY_H
#define _R3_FIELDS_SCANTY_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Scanty
	//*******************************************************************

	template <class Domain>
	class Scanty
		: public Field
	{
	public:
		static const size_t amount=Domain::amount;
	}; // class
}}  // namespace


#endif
