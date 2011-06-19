#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{
	//////////////////////////////////////////////////////////////////////////
	template<class Archive> void File::serialize(Archive &ar, const unsigned int file_version)
	{
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(Field);
		ar &BOOST_SERIALIZATION_NVP(_name);
		ar &BOOST_SERIALIZATION_NVP(_ext);
		//ar &BOOST_SERIALIZATION_NVP(_blob);
	}

	std::string &File::name()
	{
		return _name;
	}

	std::string &File::ext()
	{
		return _ext;
	}

	pgc::Blob &File::blob()
	{
		return _blob;
	}

	File &File::operator=(const std::string &from)
	{
		_name = from;
		fvs(fvs_set);
		return *this;
	}
	File &File::operator=(const pgc::Blob &from)
	{
		_blob = from;
		fvs(fvs_set);
		return *this;
	}

	File::operator std::string()
	{
		return _name;
	}
	File::operator pgc::Blob()
	{
		return _blob;
	}
}}

BOOST_CLASS_EXPORT(r3::fields::File);
