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
		Link(pgs::meta::RelationEndCPtr re);

		pgs::meta::RelationEndCPtr meta() const;
	};
}

#endif
