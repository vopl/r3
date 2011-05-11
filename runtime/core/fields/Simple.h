#ifndef _R3_FIELD_SIMPLE_H
#define _R3_FIELD_SIMPLE_H

#include "./Field.h"


namespace r3
{
	//*******************************************************************
	//   C  L  A  S  S   Simple
	//*******************************************************************
	template <bool allowNull = true>
	class Simple
		: public Field<allowNull>
	{
	public:
		Simple()
			: Field<allowNull>()
		{
		}
		
		Simple(const Simple &from)
			: Field<allowNull>(from)
		{
		}


		Simple &operator=(const Simple &from)
		{
			this->Field<allowNull>::operator=(from);
			return *this;
		}

	}; // class
}  // namespace


#endif
