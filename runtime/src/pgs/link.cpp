#include "pch.h"
#include "pgs/link.hpp"
#include "utils/implAccess.hpp"
#include "linkImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Link::Link(pgs::meta::RelationEndCPtr re, const std::string &alias)
		: Expression(utils::ImplAccess<Expression>(ImplPtr(new LinkImpl(re, alias))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Link::Link(const std::string &srcAlias, pgs::meta::RelationEndCPtr re, const std::string &alias)
		: Expression(utils::ImplAccess<Expression>(ImplPtr(new LinkImpl(srcAlias, re, alias))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::RelationEndCPtr Link::meta() const
	{
		return static_cast<LinkImpl *>(_impl.get())->meta();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Link::srcAlias() const
	{
		return static_cast<LinkImpl *>(_impl.get())->srcAlias();
	}
	
	//////////////////////////////////////////////////////////////////////////
	const std::string &Link::alias() const
	{
		return static_cast<LinkImpl *>(_impl.get())->alias();
	}

}
