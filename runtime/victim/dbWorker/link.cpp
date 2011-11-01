#include "stdafx.h"
#include "dbWorker/link.hpp"

namespace dbWorker
{
	//////////////////////////////////////////////////////////////////////////
	Link::Link(dbMeta::RelationEndCPtr re)
		: _metaRelatioEnd(re)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	dbMeta::RelationEndCPtr Link::meta() const
	{
		return _metaRelatioEnd;
	}

}
