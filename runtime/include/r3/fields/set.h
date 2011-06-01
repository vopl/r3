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
	public:
		typedef std::bitset<bits4SetAmount> TSet;

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
	}; // class
}}  // namespace


#endif
