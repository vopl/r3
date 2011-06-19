#ifndef _R3_FIELDS_BINARY_H
#define _R3_FIELDS_BINARY_H

#include "r3/fields/field.h"

namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Binary
	//*******************************************************************

	class Binary
		: public Simple
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
		typedef std::vector<char> TValue;
	private:
		TValue _value;
	public:
		Binary();
		Binary(const TValue &from);

		TValue &value();
		const TValue &value() const;

		Binary &operator=(const TValue &from);
		bool operator==(const TValue &with) const;

		Binary &operator=(EFieldValueState from);
		bool operator==(EFieldValueState fvs) const;

	}; // class
}}  // namespace


#endif
