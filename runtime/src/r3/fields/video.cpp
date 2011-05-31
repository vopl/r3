#include "stdafx.h"
#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	boost::int32_t &Video::width()
	{
		return _width;
	}

	boost::int32_t &Video::height()
	{
		return _height;
	}

}}
