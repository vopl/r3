#ifndef _R3_FIELD_FIELD_H
#define _R3_FIELD_FIELD_H

#include "r3/fields/Field.h"


namespace r3{ namespace fields
{
	enum EFieldValueState
	{
		fvs_null,
		fvs_notset,
		fvs_set,
	};

	#pragma pack(push, 1)
	//*******************************************************************
	//   C  L  A  S  S   Field
	//*******************************************************************
	class Field
	{
	private:
		EFieldValueState _fvs;

	protected:
		Field()
			: _fvs(fvs_notset)
		{
		}

		Field(const Field &from)
			: _fvs(from._fvs)
		{
		}


		Field &operator=(const Field &from)
		{
			_fvs = from._fvs;
			return *this;
		}

	public:
		EFieldValueState fvs() const
		{
			return _fvs;
		}

		EFieldValueState fvs(EFieldValueState fvs)
		{
			EFieldValueState prev = _fvs;
			_fvs = fvs;
			return prev;
		}
	}; // class
}}  // namespace


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
