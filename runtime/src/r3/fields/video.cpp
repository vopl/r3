#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


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

BOOST_CLASS_EXPORT(r3::fields::Video);
