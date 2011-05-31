#include "stdafx.h"
#include "r3/fields/field.h"


namespace r3{ namespace fields
{

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
