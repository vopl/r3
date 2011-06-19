#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{
	//////////////////////////////////////////////////////////////////////////
	template<class Archive> void Image::serialize(Archive &ar, const unsigned int file_version)
	{
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(File);
		ar &BOOST_SERIALIZATION_NVP(_width);
		ar &BOOST_SERIALIZATION_NVP(_height);
	}

	boost::int32_t &Image::width()
	{
		return _width;
	}

	boost::int32_t &Image::height()
	{
		return _height;
	}

}}

BOOST_CLASS_EXPORT(r3::fields::Image);
