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
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

		static BoostGuidIniter<Enum<Domain> > _BoostGuidIniter;

	public:
		typedef typename Scanty<Domain>::Integral TValue;
	private:
		TValue _value;
	public:
		Enum();
		Enum(const TValue &from);

		TValue &value();
		const TValue &value() const;

		Enum &operator=(r3::fields::EFieldValueState fvs);
		Enum &operator=(const TValue &from);

		bool operator==(r3::fields::EFieldValueState fvs);
		bool operator==(const TValue &with);
	}; // class

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	BoostGuidIniter<Enum<Domain> > Enum<Domain>::_BoostGuidIniter;


	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	template<class Archive> 
	void Enum<Domain>::serialize(Archive &ar, const unsigned int file_version)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline Enum<Domain>::Enum()
		: _value()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline Enum<Domain>::Enum(const TValue &from)
		: Scanty<Domain>()
		, _value(from)
	{
		Scanty<Domain>::fvs(fvs_set);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline typename Enum<Domain>::TValue &Enum<Domain>::value()
	{
		return _value;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline const typename Enum<Domain>::TValue &Enum<Domain>::value() const
	{
		return _value;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class Domain>
	inline Enum<Domain> &Enum<Domain>::operator=(const TValue &from)
	{
		Scanty<Domain>::fvs(fvs_set);
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
	bool Enum<Domain>::operator==(const TValue &with)
	{
		if(Scanty<Domain>::fvs() != fvs_set)
		{
			return false;
		}

		return _value == with;
	}

}}  // namespace

#endif
