#include "stdafx.h"
#include "r3/fields/field.h"
#include "utils/serialization.hpp"


namespace r3{ namespace fields
{
	template<class Archive> void Field::serialize(Archive &ar, const unsigned int file_version)
	{
		ar &BOOST_SERIALIZATION_NVP(_fvs);
	}


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

	Field::~Field()
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

BOOST_CLASS_EXPORT(r3::fields::Field);
