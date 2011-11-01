#include "stdafx.h"
#include "dbWorker/field.hpp"

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	Field::Field(dbMeta::FieldCPtr fld)
		: _metaField(fld)
	{
	}
}
