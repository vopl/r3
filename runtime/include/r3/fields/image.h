#ifndef _R3_FIELDS_IMAGE_H
#define _R3_FIELDS_IMAGE_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Image
	//*******************************************************************

	class Image
		: public File
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
