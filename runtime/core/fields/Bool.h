#ifndef _R3_FIELD_BOOL_H
#define _R3_FIELD_BOOL_H

#include "./Field.h"


namespace r3
{
	//*******************************************************************
	//   C  L  A  S  S   Bool
	//*******************************************************************
	template <bool allowNull = true>
	class Bool
		: public Simple<allowNull>
	{
		bool _value;

	public:
		Bool()
			: Simple<allowNull>()
			, _value(false)
		{
		}

		Bool(const Bool &from)
			: Simple<allowNull>(from)
			, _value(from._value)
		{
		}

		Bool(bool from)
			: Simple<allowNull>()
			, _value(from)
		{
			isNull(false);
		}

		Bool &operator=(const Bool &from)
		{
			this->Simple<allowNull>::operator=(from);
			_value = from._value;
			return *this;
		}

		Bool &operator=(bool from)
		{
			_value = from;
			isNull(false);
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
}  // namespace


#endif
