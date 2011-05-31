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
		bool _value;

	public:
		Bool()
			: Simple()
			, _value(false)
		{
		}

		Bool(const Bool &from)
			: Simple(from)
			, _value(from._value)
		{
		}

		Bool(bool from)
			: Simple()
			, _value(from)
		{
			fvs(fvs_set);
		}

		bool &value()
		{
			return _value;
		}

		Bool &operator=(const Bool &from)
		{
			this->Simple::operator=(from);
			_value = from._value;
			return *this;
		}

		Bool &operator=(bool from)
		{
			_value = from;
			fvs(fvs_set);
			return *this;
		}

		operator bool()
		{
			return _value;
		}

		bool operator !()
		{
			return !_value;
		}


	}; // class
}}  // namespace


#endif
