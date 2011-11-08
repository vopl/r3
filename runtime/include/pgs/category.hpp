#ifndef _PGS_CATEGORY_HPP_
#define _PGS_CATEGORY_HPP_

#include "pgs/expression.hpp"
#include "meta/common.hpp"

namespace pgs
{
	namespace impl
	{
		class Category;
		typedef boost::shared_ptr<Category> Category_ptr;
	}

	//////////////////////////////////////////////////////////////////////////
	class Category
		: public Expression
	{
	public:
		typedef impl::Category_ptr Impl_ptr;

	public:
		Category();
		Category(pgs::meta::CategoryCPtr cat, const std::string &alias="");

		pgs::meta::CategoryCPtr meta() const;
		const std::string &alias() const;
	};
}

#endif
