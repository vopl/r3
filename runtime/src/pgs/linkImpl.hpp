#ifndef _PGS_IMPL_LINK_HPP_
#define _PGS_IMPL_LINK_HPP_

#include "expressionImpl.hpp"
#include "pgs/meta/relationEnd.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class LinkImpl
		: public ExpressionImpl
	{
		pgs::meta::RelationEndCPtr _metaRelatioEnd;
		std::string _srcAlias;
		std::string _alias;
	public:
		LinkImpl(pgs::meta::RelationEndCPtr re, const std::string &alias="");
		LinkImpl(const std::string &srcAlias, pgs::meta::RelationEndCPtr re, const std::string &alias="");

		pgs::meta::RelationEndCPtr meta() const;
		const std::string &srcAlias() const;
		const std::string &alias() const;

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};
	typedef boost::shared_ptr<LinkImpl> LinkImpl_ptr;
}

#endif
