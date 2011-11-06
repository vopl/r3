#include "stdafx.h"
#include "link.hpp"

namespace pgs
{
	namespace impl
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
}
