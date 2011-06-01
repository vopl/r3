#include "stdafx.h"
#include "r3/fields/field.h"


namespace r3{ namespace fields
{

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
