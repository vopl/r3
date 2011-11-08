#include "stdafx.h"
#include "pgs/link.hpp"
#include "impl/access.hpp"
#include "impl/link.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Link::Link(pgs::meta::RelationEndCPtr re, const std::string &alias)
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Link(re, alias))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Link::Link(const std::string &srcAlias, pgs::meta::RelationEndCPtr re, const std::string &alias)
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Link(srcAlias, re, alias))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::RelationEndCPtr Link::meta() const
	{
		return static_cast<impl::Link *>(_impl.get())->meta();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Link::srcAlias() const
	{
		return static_cast<impl::Link *>(_impl.get())->srcAlias();
	}
	
	//////////////////////////////////////////////////////////////////////////
	const std::string &Link::alias() const
	{
		return static_cast<impl::Link *>(_impl.get())->alias();
	}

}
