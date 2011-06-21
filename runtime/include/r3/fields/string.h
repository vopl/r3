#ifndef _R3_FIELDS_STRING_H
#define _R3_FIELDS_STRING_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   String
	//*******************************************************************

	class String
		: public Simple
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
		typedef std::string TValue;
	private:
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

		std::string &value()
		{
			return _value;
		}
		const std::string &value() const
		{
			return _value;
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

		String &operator=(EFieldValueState from)
		{
			Field::operator =(from);
			return *this;
		}

		bool operator==(const char *with)
		{
			if(fvs()!=fvs_set)
			{
				return false;
			}
			return _value == with;
		}
		bool operator==(const std::string &with)
		{
			if(fvs()!=fvs_set)
			{
				return false;
			}
			return _value == with;
		}

		bool operator==(EFieldValueState from)
		{
			return Field::operator ==(from);
		}

		bool operator!=(const char *with)
		{
			return !operator==(with);
		}
		bool operator!=(const std::string &with)
		{
			return !operator==(with);
		}

		bool operator!=(EFieldValueState from)
		{
			return !operator==(from);
		}

	}; // class
}}  // namespace


#endif
