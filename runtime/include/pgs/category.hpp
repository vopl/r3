#ifndef _PGS_CATEGORY_HPP_
#define _PGS_CATEGORY_HPP_

#include "pgs/expression.hpp"
#include "meta/common.hpp"

namespace pgs
{
	class CategoryImpl;
	typedef boost::shared_ptr<CategoryImpl> CategoryImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Category
		: public Expression
	{
	public:
		typedef CategoryImplPtr ImplPtr;

	public:
		Category(pgs::meta::CategoryCPtr cat, const std::string &alias="");

		pgs::meta::CategoryCPtr meta() const;
		const std::string &alias() const;
	};
}

#endif
