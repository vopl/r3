#ifndef _R3_FIELDS_INT64_H
#define _R3_FIELDS_INT64_H

#include "r3/fields/field.h"

namespace r3{ namespace fields
{
	//*******************************************************************
	//   C  L  A  S  S   Int64
	//*******************************************************************

	class Int64
		: public Int<boost::int64_t>
	{
		friend class boost::serialization::access;
		template<class Archive> void serialize(Archive &ar, const unsigned int file_version);

	public:
		void operator=(boost::int8_t from)
		{
			fvs(fvs_set);
			_value = from;
		}
		void operator=(boost::int16_t from)
		{
			fvs(fvs_set);
			_value = from;
		}
		void operator=(boost::int32_t from)
		{
			fvs(fvs_set);
			_value = from;
		}
		void operator=(boost::int64_t from)
		{
			fvs(fvs_set);
			_value = from;
		}






		bool operator==(boost::int8_t with) const
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}
		bool operator==(boost::int16_t with) const
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}
		bool operator==(boost::int32_t with) const
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}
		bool operator==(boost::int64_t with) const
		{
			if(fvs() != fvs_set)
			{
				return false;
			}
			return _value == with;
		}

		bool operator==(Int64 with) const
		{
			if(!Field::operator ==(with))
			{
				return false;
			}
			return _value == with._value;
		}

		using Int<boost::int64_t>::operator ==;
	}; // class
}}  // namespace


#endif
