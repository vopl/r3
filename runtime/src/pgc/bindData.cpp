#include "pch.h"
#include "bindData.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	BindData::BindData(const utils::Variant &data)
		: typ(_bindTyp)
		, val(_bindVal)
		, len(_bindLen)
		, fmt(_bindFmt)
	{
		assert(0);
		switch(data.type())
		{
		case utils::Variant::etVectorVariant:
		case utils::Variant::etSetVariant:
		case utils::Variant::etDequeVariant:
		case utils::Variant::etListVariant:
			//bindSeq
			break;
		case utils::Variant::etMapStringVariant:
		case utils::Variant::etMapVariantVariant:
		case utils::Variant::etMultimapVariantVariant:
		case utils::Variant::etMultimapStringVariant:
		case utils::Variant::etMultisetVariant:
			//bindAssoc
			break;

		case utils::Variant::etString:
		case utils::Variant::etFloat:
		case utils::Variant::etDouble:
		case utils::Variant::etInt8:
		case utils::Variant::etInt16:
		case utils::Variant::etInt32:
		case utils::Variant::etInt64:
		case utils::Variant::etUInt8:
		case utils::Variant::etUInt16:
		case utils::Variant::etUInt32:
		case utils::Variant::etUInt64:
		case utils::Variant::etVectorChar:
		case utils::Variant::etDate:
		case utils::Variant::etTime:
		case utils::Variant::etBool:
		case utils::Variant::etTm:
		case utils::Variant::etBitset8:
		case utils::Variant::etBitset16:
		case utils::Variant::etBitset32:
		case utils::Variant::etBitset64:
		case utils::Variant::etBitset128:
		case utils::Variant::etBitset256:
		case utils::Variant::etBitset512:
		case utils::Variant::etDateDuration:
		case utils::Variant::etTimeDuration:
		case utils::Variant::etDateTimeDuration:
		case utils::Variant::etChar:
		case utils::Variant::etUuid:
			break;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	BindData::~BindData()
	{

	}

}