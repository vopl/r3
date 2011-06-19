#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{
	//////////////////////////////////////////////////////////////////////////
	template<class Archive> void Real::serialize(Archive &ar, const unsigned int file_version)
	{

	}


}}

BOOST_CLASS_EXPORT(r3::fields::Real);
