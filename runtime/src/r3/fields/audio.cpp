#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{
	//////////////////////////////////////////////////////////////////////////
	template<class Archive> void Audio::serialize(Archive &ar, const unsigned int file_version)
	{
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(File);
	}


	Audio &Audio::operator=(const std::string &from)
	{
		File::operator =(from);
		return *this;
	}

	Audio &Audio::operator=(const pgc::Blob &from)
	{
		File::operator =(from);
		return *this;
	}

}}

BOOST_CLASS_EXPORT(r3::fields::Audio);
