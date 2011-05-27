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
	public:
		Simple()
			: Field()
		{
		}
		
		Simple(const Simple &from)
			: Field(from)
		{
		}


		Simple &operator=(const Simple &from)
		{
			this->Field::operator=(from);
			return *this;
		}

	}; // class
}}  // namespace


#endif
