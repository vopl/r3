#ifndef _R3_FIELDS_FIELD_H
#define _R3_FIELDS_FIELD_H


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
		Field();
		Field(const Field &v);
		Field (EFieldValueState v);
		void operator=(const Field &v);
		bool operator==(const Field &v) const;
		bool operator!=(const Field &v) const;

	public:
		void operator=(EFieldValueState v);
		bool operator==(EFieldValueState v) const;
		bool operator!=(EFieldValueState v) const;

		EFieldValueState fvs() const;
		EFieldValueState fvs(EFieldValueState v);
	}; // class
}}  // namespace


//////////////////////////////////////////////////////////////////////////
#include "./file.h"
#include "./audio.h"
#include "./image.h"
#include "./video.h"

#include "./simple.h"
#include "./bool.h"
#include "./money.h"
#include "./string.h"

#include "./scanty.h"
#include "./enum.h"
#include "./set.h"

#include "./int.h"
#include "./int8.h"
#include "./int16.h"
#include "./int32.h"
#include "./int64.h"

#include "./real.h"
#include "./real32.h"
#include "./real64.h"

#include "./dateTime.h"
#include "./dateTimeValue.h"
#include "./date.h"
#include "./time.h"
#include "./timestamp.h"
#include "./dateTimeInterval.h"

#include "./id.h"

#pragma pack(pop)


#endif
