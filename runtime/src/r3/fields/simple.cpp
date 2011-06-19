#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{
	//////////////////////////////////////////////////////////////////////////
	template<class Archive> void Simple::serialize(Archive &ar, const unsigned int file_version)
	{

	}

	Simple::Simple()
		: Field()
	{
	}
	
	Simple::Simple(const Simple &v)
		: Field(v)
	{

	}

}}

BOOST_CLASS_EXPORT(r3::fields::Simple);
