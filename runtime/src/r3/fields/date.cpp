#include "stdafx.h"
#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	Date::Date()
		: _value()
	{

	}

	Date::Date(const boost::gregorian::date &from)
		: DateTimeValue()
		, _value(from)
	{
		fvs(fvs_set);
	}

	boost::gregorian::date &Date::value()
	{
		return _value;
	}

	const boost::gregorian::date &Date::value() const
	{
		return _value;
	}

	Date &Date::operator=(const boost::gregorian::date &from)
	{
		fvs(fvs_set);
		_value = from;
		return *this;
	}

	bool Date::operator==(const boost::gregorian::date &with) const
	{
		if(fvs() != fvs_set)
		{
			return false;
		}

		return _value == with;
	}

	Date::operator boost::gregorian::date ()const
	{
		return _value;
	}


	Date &Date::operator=(EFieldValueState from)
	{
		Field::operator =(from);
		return *this;
	}

}}
