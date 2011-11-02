#include "stdafx.h"
#include "pgs/link.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Link::Link(pgs::meta::RelationEndCPtr re)
		: _metaRelatioEnd(re)
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::RelationEndCPtr Link::meta() const
	{
		return _metaRelatioEnd;
	}

}
