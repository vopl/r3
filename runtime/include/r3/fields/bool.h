#ifndef _R3_FIELDS_BOOL_H
#define _R3_FIELDS_BOOL_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Bool
	//*******************************************************************

	class Bool
		: public Simple
	{
	public:
		typedef bool TValue;
	private:
		bool _value;

	public:
		Bool();
		Bool(bool from);

		bool &value();
		const bool &value() const;
		Bool &operator=(bool from);
		operator bool() const;
		bool operator !() const;


	}; // class
}}  // namespace


#endif
