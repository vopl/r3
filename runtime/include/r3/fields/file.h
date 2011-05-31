#ifndef _R3_FIELDS_FILE_H
#define _R3_FIELDS_FILE_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   File
	//*******************************************************************
	class File
		: public Field
	{
		boost::uint32_t _value;
	public:
		boost::uint32_t &value()
		{
			return _value;
		}
	}; // class
}}  // namespace


#endif
