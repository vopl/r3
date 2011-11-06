#ifndef _PGS_IMPL_LINK_HPP_
#define _PGS_IMPL_LINK_HPP_

#include "expression.hpp"
#include "pgs/meta/relationEnd.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Link
			: public Expression
		{
			pgs::meta::RelationEndCPtr _metaRelatioEnd;
		public:
			Link(pgs::meta::RelationEndCPtr re);

			pgs::meta::RelationEndCPtr meta() const;
		};
		typedef boost::shared_ptr<Link> Link_ptr;
	}
}

#endif
