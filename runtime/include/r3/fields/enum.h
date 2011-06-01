#ifndef _R3_FIELDS_ENUM_H
#define _R3_FIELDS_ENUM_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Enum
	//*******************************************************************

	template <class Domain>
	class Enum
		: public Scanty<Domain>
	{
	public:
		typedef Integral TValue;
	private:
		Integral _value;
	public:
		Enum();
		Enum(const Integral &from);

		Integral &value();
		const Integral &value() const;

		Enum &operator=(r3::fields::EFieldValueState fvs);
		Enum &operator=(const Integral &from);

		bool operator==(r3::fields::EFieldValueState fvs);
		bool operator==(const Integral &with);
	}; // class


	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline Enum<Domain>::Enum()
		: _value()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline Enum<Domain>::Enum(const Integral &from)
		: Scanty<Domain>()
		, _value(from)
	{
		fvs(fvs_set);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline typename Enum<Domain>::Integral &Enum<Domain>::value()
	{
		return _value;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline const typename Enum<Domain>::Integral &Enum<Domain>::value() const
	{
		return _value;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline Enum<Domain> &Enum<Domain>::operator=(const Integral &from)
	{
		fvs(fvs_set);
		_value = from;

		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	Enum<Domain> &Enum<Domain>::operator=(r3::fields::EFieldValueState fvs)
	{
		Field::operator =(fvs);
		return *this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	bool Enum<Domain>::operator==(r3::fields::EFieldValueState fvs)
	{
		return Field::operator ==(fvs);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	bool Enum<Domain>::operator==(const Integral &with)
	{
		if(fvs() != fvs_set)
		{
			return false;
		}

		return _value == with;
	}



}}  // namespace


#endif
