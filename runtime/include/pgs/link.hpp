#ifndef _PGS_LINK_HPP_
#define _PGS_LINK_HPP_

#include "pgs/expression.hpp"
#include "meta/common.hpp"

namespace pgs
{
	namespace impl
	{
		class Link;
		typedef boost::shared_ptr<Link> Link_ptr;
	}

	//////////////////////////////////////////////////////////////////////////
	class Link
		: public Expression
	{

	public:
		typedef impl::Link_ptr Impl_ptr;

	public:
		Link(pgs::meta::RelationEndCPtr re, const std::string &alias="");
		Link(const std::string &srcAlias, pgs::meta::RelationEndCPtr re, const std::string &alias="");

		pgs::meta::RelationEndCPtr meta() const;
		const std::string &srcAlias() const;
		const std::string &alias() const;
	};
}

#endif
