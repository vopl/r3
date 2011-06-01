#include "stdafx.h"
#include "r3/fields/field.h"


namespace r3{ namespace fields
{

	Field::Field()
		: _fvs(fvs_notset)
	{
	}

	Field::Field(const Field &from)
		: _fvs(from._fvs)
	{
	}
	Field::Field(EFieldValueState from)
		: _fvs(from)
	{

	}


	Field &Field::operator=(const Field &from)
	{
		_fvs = from._fvs;
		return *this;
	}

	Field &Field::operator=(EFieldValueState from)
	{
		_fvs = from;
		return *this;
	}

	bool Field::operator==(const Field &with) const
	{
		return _fvs == with._fvs;
	}
	bool Field::operator==(const EFieldValueState with) const
	{
		return _fvs == with;
	}


	EFieldValueState Field::fvs() const
	{
		return _fvs;
	}

	EFieldValueState Field::fvs(EFieldValueState fvs)
	{
		EFieldValueState prev = _fvs;
		_fvs = fvs;
		return prev;
	}
}}
