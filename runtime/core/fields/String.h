#ifndef _R3_FIELD_STRING_H
#define _R3_FIELD_STRING_H

#include "./Field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   String
	//*******************************************************************

	class String
		: public Simple
	{
		std::string _value;

	public:
		String()
			: Simple()
			, _value()
		{
		}

		String(const String &from)
			: Simple(from)
			, _value(from._value)
		{
		}

		String(const std::string &from)
			: Simple()
			, _value(from)
		{
			fvs(fvs_set);
		}

		String(const char *from)
			: Simple()
			, _value(from?from:"")
		{
			fvs(from?fvs_set:fvs_null);
		}

		String &operator=(const String &from)
		{
			this->Simple::operator=(from);
			_value = from._value;
			return *this;
		}

		String &operator=(const std::string &from)
		{
			_value = from;
			fvs(fvs_set);
			return *this;
		}
		String &operator=(const char *from)
		{
			_value = from?from:"";
			fvs(from?fvs_set:fvs_null);
			return *this;
		}

		operator std::string()
		{
			return _value;
		}
		operator const char *()
		{
			return fvs_set == fvs()?NULL:_value.c_str();
		}

	}; // class
}}  // namespace


#endif
