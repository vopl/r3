#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{
	//////////////////////////////////////////////////////////////////////////
	template<class Archive> void Date::serialize(Archive &ar, const unsigned int file_version)
	{
		ar &BOOST_SERIALIZATION_BASE_OBJECT_NVP(DateTimeValue);
		//ar &BOOST_SERIALIZATION_NVP(_value);
	}

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

	bool Date::operator==(EFieldValueState fvs) const
	{
		return Field::operator ==(fvs);
	}

}}

BOOST_CLASS_EXPORT(r3::fields::Date);
