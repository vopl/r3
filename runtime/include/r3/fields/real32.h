#ifndef _R3_FIELDS_REAL32_H
#define _R3_FIELDS_REAL32_H

#include "r3/fields/field.h"


namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Real32
	//*******************************************************************

	class Real32
		: public Real
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
		typedef float TValue;
	private:
		float _value;
	public:
		Real32()
			: _value(0)
		{

		}
		float &value()
		{
			return _value;
		}

		Real32 &operator=(boost::int8_t from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Real32 &operator=(boost::int16_t from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Real32 &operator=(boost::int32_t from)
		{
			fvs(fvs_set);
			_value = (float)from;
			return *this;
		}
		Real32 &operator=(boost::int64_t from)
		{
			fvs(fvs_set);
			_value = (float)from;
			return *this;
		}

		Real32 &operator=(float from)
		{
			fvs(fvs_set);
			_value = from;
			return *this;
		}
		Real32 &operator=(double from)
		{
			fvs(fvs_set);
			_value = (float)from;
			return *this;
		}

		bool operator==(float with) const
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}

		bool operator==(double with) const
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}

		bool operator==(EFieldValueState fvs) const
		{
			return Field::operator ==(fvs);
		}

	}; // class
}}  // namespace


#endif
