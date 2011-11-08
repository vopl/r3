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
			std::string _srcAlias;
			std::string _alias;
		public:
			Link(pgs::meta::RelationEndCPtr re, const std::string &alias="");
			Link(const std::string &srcAlias, pgs::meta::RelationEndCPtr re, const std::string &alias="");

			pgs::meta::RelationEndCPtr meta() const;
			const std::string &srcAlias() const;
			const std::string &alias() const;

		};
		typedef boost::shared_ptr<Link> Link_ptr;
	}
}

#endif
