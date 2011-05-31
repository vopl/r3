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
		_value = from;
		return *this;
	}

	Date::operator boost::gregorian::date ()const
	{
		return _value;
	}


}}
