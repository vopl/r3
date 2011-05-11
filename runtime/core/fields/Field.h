#ifndef _R3_FIELD_FIELD_H
#define _R3_FIELD_FIELD_H

#include "./Field.h"


namespace r3
{
	#pragma pack(push, 1)
	//*******************************************************************
	//   C  L  A  S  S   Field
	//*******************************************************************
	template <bool allowNull = true>
	class Field
	{
		bool _isNull;
	public:
		Field()
			: _isNull(true)
		{
		}

		Field(const Field &from)
			: _isNull(from._isNull)
		{
		}


		Field &operator=(const Field &from)
		{
			_isNull = from._isNull;
			return *this;
		}

		bool isNull() const
		{
			return _isNull;
		}

		bool isNull(bool b)
		{
			bool prev = _isNull;
			_isNull = b;
			return prev;
		}

		bool isValid() const
		{
			return allowNull?true:!_isNull;
		}
	}; // class
}  // namespace


//////////////////////////////////////////////////////////////////////////

#include "./File.h"
#include "./Audio.h"
#include "./Image.h"
#include "./Video.h"

#include "./Simple.h"
#include "./Bool.h"
#include "./Money.h"
#include "./String.h"

#include "./Scanty.h"
#include "./Enum.h"
#include "./Set.h"

#include "./Int.h"
#include "./Int8.h"
#include "./Int16.h"
#include "./Int32.h"
#include "./Int64.h"

#include "./Real.h"
#include "./Real32.h"
#include "./Real64.h"

#include "./DateTime.h"
#include "./DateTimeValue.h"
#include "./Date.h"
#include "./Time.h"
#include "./Timestamp.h"
#include "./DateTimeInterval.h"

#pragma pack(pop)


#endif
