#ifndef _PGS_CATEGORYIMPL_HPP_
#define _PGS_CATEGORYIMPL_HPP_

#include "pgs/category.hpp"
#include "expressionImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class CategoryImpl
		: public ExpressionImpl
	{
		pgs::meta::CategoryCPtr _metaCategory;
		std::string _alias;

	public:
		CategoryImpl(pgs::meta::CategoryCPtr cat, const std::string &alias="");

		pgs::meta::CategoryCPtr meta() const;
		const std::string &alias() const;

		virtual void compile(std::deque<std::string> &res, SCompileState &state, ECompileMode ecm);
	};
	typedef boost::shared_ptr<CategoryImpl> CategoryImplPtr;
}

#endif
