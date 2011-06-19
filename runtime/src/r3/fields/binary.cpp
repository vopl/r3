#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{
	Binary::Binary()
		: Simple()
		, _value()
	{

	}

	Binary::Binary(const TValue &from)
		: Simple()
		, _value(from)
	{
		fvs(fvs_set);
	}

	Binary::TValue &Binary::value()
	{
		return _value;
	}

	const Binary::TValue &Binary::value() const
	{
		return _value;
	}

	Binary &Binary::operator=(const TValue &from)
	{
		fvs(fvs_set);
		_value = from;
		return *this;
	}

	bool Binary::operator==(const TValue &with) const
	{
		if(fvs() != fvs_set)
		{
			return false;
		}

		return _value == with;
	}


	Binary &Binary::operator=(EFieldValueState from)
	{
		Field::operator =(from);
		return *this;
	}

	bool Binary::operator==(EFieldValueState fvs) const
	{
		return Field::operator ==(fvs);
	}

}}

BOOST_CLASS_EXPORT(r3::fields::Binary);
