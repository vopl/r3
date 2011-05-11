#ifndef _R3_FIELD_STRING_H
#define _R3_FIELD_STRING_H

#include "./Field.h"


namespace r3
{
	//*******************************************************************
	//   C  L  A  S  S   String
	//*******************************************************************
	template <bool allowNull = true>
	class String
		: public Simple<allowNull>
	{
		std::string _value;

	public:
		String()
			: Simple<allowNull>()
			, _value()
		{
		}

		String(const String &from)
			: Simple<allowNull>(from)
			, _value(from._value)
		{
		}

		String(const std::string &from)
			: Simple<allowNull>()
			, _value(from)
		{
			isNull(false);
		}

		String(const char *from)
			: Simple<allowNull>()
			, _value(from?from:"")
		{
			isNull(from?false:true);
		}

		String &operator=(const String &from)
		{
			this->Simple<allowNull>::operator=(from);
			_value = from._value;
			return *this;
		}

		String &operator=(const std::string &from)
		{
			_value = from;
			isNull(false);
			return *this;
		}
		String &operator=(const char *from)
		{
			_value = from?from:"";
			isNull(from?false:true);
			return *this;
		}

		operator std::string()
		{
			return _value;
		}
		operator const char *()
		{
			return isNull()?NULL:_value.c_str();
		}

	}; // class
}  // namespace


#endif
