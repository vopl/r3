#include "stdafx.h"
#include "r3/fields/field.h"


namespace r3{ namespace fields
{

	//////////////////////////////////////////////////////////////////////////
	Money::Money()
	{

	}


	//////////////////////////////////////////////////////////////////////////
	Money::Money(const boost::int64_t &from)
	{
		fvs(fvs_set);
		_value._value = from;
	}

	//////////////////////////////////////////////////////////////////////////
	pgc::Money &Money::value()
	{
		return _value;
	}
	
	//////////////////////////////////////////////////////////////////////////
	const pgc::Money &Money::value() const
	{
		return _value;
	}

	//////////////////////////////////////////////////////////////////////////
	Money &Money::operator=(r3::fields::EFieldValueState fvs)
	{
		Field::operator =(fvs);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Money &Money::operator=(const boost::int64_t &from)
	{
		fvs(fvs_set);
		_value._value = from;
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Money &Money::operator=(const boost::int32_t &from)
	{
		fvs(fvs_set);
		_value._value = from;
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Money &Money::operator=(float from)
	{
		fvs(fvs_set);
		_value._value = (boost::int64_t)((0.005 + from)*100);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	Money &Money::operator=(double from)
	{
		fvs(fvs_set);
		_value._value = (boost::int64_t)((0.005 + from)*100);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Money::operator==(r3::fields::EFieldValueState fvs)
	{
		return Field::operator==(fvs);
	}


	//////////////////////////////////////////////////////////////////////////
	bool Money::operator==(const Money &with)
	{
		if(!Simple::operator ==(with))
		{
			return false;
		}
		return _value._value == with._value._value;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Money::operator==(const boost::int32_t &with)
	{
		if(fvs() != fvs_set)
		{
			return false;
		}
		return _value._value == with;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Money::operator==(const boost::int64_t &with)
	{
		if(fvs() != fvs_set)
		{
			return false;
		}
		return _value._value == with;
	}

}}
