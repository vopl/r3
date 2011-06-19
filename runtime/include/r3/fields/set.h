#ifndef _R3_FIELDS_SET_H
#define _R3_FIELDS_SET_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Set
	//*******************************************************************

	template <class Domain>
	class Set
		: public Scanty<Domain>
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

		static BoostGuidIniter<Set<Domain> > _BoostGuidIniter;

	public:
		typedef std::bitset<Scanty<Domain>::bits4SetAmount> TSet;

	public:
		typedef TSet TValue;
	private:
	private:
		TSet _value;

	public:
		TSet &value()
		{
			return _value;
		}

		Set &operator=(EFieldValueState from)
		{
			Field::operator =(from);
			return *this;
		}

		bool operator==(EFieldValueState fvs) const
		{
			return Field::operator ==(fvs);
		}

		bool operator==(const TSet &with) const
		{
			if(Scanty<Domain>::fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}

	}; // class
}}  // namespace


#endif
