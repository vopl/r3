#ifndef _PGS_LINK_HPP_
#define _PGS_LINK_HPP_

#include "pgs/expression.hpp"
#include "meta/common.hpp"

namespace pgs
{
	class LinkImpl;
	typedef boost::shared_ptr<LinkImpl> LinkImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Link
		: public Expression
	{

	public:
		typedef LinkImplPtr ImplPtr;

	public:
		Link(pgs::meta::RelationEndCPtr re, const std::string &alias="");
		Link(const std::string &srcAlias, pgs::meta::RelationEndCPtr re, const std::string &alias="");

		pgs::meta::RelationEndCPtr meta() const;
		const std::string &srcAlias() const;
		const std::string &alias() const;
	};
}

#endif
