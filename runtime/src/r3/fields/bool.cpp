#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{

	Bool::Bool()
		: Simple()
		, _value(false)
	{
	}

	Bool::Bool(bool from)
		: Simple()
		, _value(from)
	{
		fvs(fvs_set);
	}

	bool &Bool::value()
	{
		return _value;
	}
	const bool &Bool::value() const
	{
		return _value;
	}

	Bool &Bool::operator=(bool from)
	{
		_value = from;
		fvs(fvs_set);
		return *this;
	}

	Bool::operator bool() const
	{
		return _value;
	}

	bool Bool::operator !() const
	{
		return !_value;
	}
}}

BOOST_CLASS_EXPORT(r3::fields::Bool);
