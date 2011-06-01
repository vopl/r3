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
		Field(const Field &from);
		Field (EFieldValueState from);
		Field &operator=(const Field &from);
		bool operator==(const Field &with) const;

	public:
		Field &operator=(EFieldValueState from);
		bool operator==(const EFieldValueState with) const;

		EFieldValueState fvs() const;
		EFieldValueState fvs(EFieldValueState fvs);
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
