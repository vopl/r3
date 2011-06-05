#include "stdafx.h"
#include "r3/fields/field.h"


namespace r3{ namespace fields
{

	Field::Field()
		: _fvs(fvs_notset)
	{
	}

	Field::Field(const Field &v)
		: _fvs(v._fvs)
	{
	}
	Field::Field(EFieldValueState v)
		: _fvs(v)
	{

	}


	void Field::operator=(const Field &v)
	{
		_fvs = v._fvs;
	}

	void Field::operator=(EFieldValueState v)
	{
		_fvs = v;
	}

	bool Field::operator==(const Field &v) const
	{
		return _fvs == v._fvs;
	}
	bool Field::operator!=(const Field &v) const
	{
		return !operator==(v);
	}
	bool Field::operator==(EFieldValueState v) const
	{
		return _fvs == v;
	}
	bool Field::operator!=(EFieldValueState v) const
	{
		return !operator==(v);
	}


	EFieldValueState Field::fvs() const
	{
		return _fvs;
	}

	EFieldValueState Field::fvs(EFieldValueState v)
	{
		EFieldValueState prev = _fvs;
		_fvs = v;
		return prev;
	}
}}
