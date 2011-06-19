#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{

	template<class Archive> void String::serialize(Archive &ar, const unsigned int file_version)
	{
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(Simple);
		ar &BOOST_SERIALIZATION_NVP(_value);
	}

}}

BOOST_CLASS_EXPORT(r3::fields::String);
