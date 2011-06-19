#ifndef _R3_FIELDS_DATE_H
#define _R3_FIELDS_DATE_H

#include "r3/fields/field.h"

namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Date
	//*******************************************************************

	class Date
		: public DateTimeValue
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
		typedef boost::gregorian::date TValue;
	private:
		boost::gregorian::date _value;
	public:
		Date();
		Date(const boost::gregorian::date &from);

		boost::gregorian::date &value();
		const boost::gregorian::date &value() const;

		Date &operator=(const boost::gregorian::date &from);
		bool operator==(const boost::gregorian::date &with) const;
		operator boost::gregorian::date ()const;

		Date &operator=(EFieldValueState from);
		bool operator==(EFieldValueState fvs) const;

	}; // class
}}  // namespace


#endif
