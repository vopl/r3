#include "stdafx.h"
#include "pgs/link.hpp"
#include "impl/access.hpp"
#include "impl/link.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Link::Link(pgs::meta::RelationEndCPtr re)
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Link(re))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::RelationEndCPtr Link::meta() const
	{
		return static_cast<impl::Link *>(_impl.get())->meta();
	}

}
