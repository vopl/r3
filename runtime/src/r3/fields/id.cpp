#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{
	//////////////////////////////////////////////////////////////////////////
	template<class Archive> void Id::serialize(Archive &ar, const unsigned int file_version)
	{
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(Int64);
	}


}}

BOOST_CLASS_EXPORT(r3::fields::Id);
