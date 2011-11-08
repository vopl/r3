#ifndef _PGS_IMPL_CATEGORY_HPP_
#define _PGS_IMPL_CATEGORY_HPP_

#include "pgs/category.hpp"
#include "expression.hpp"

namespace pgs
{
	namespace impl
	{
		//////////////////////////////////////////////////////////////////////////
		class Category
			: public impl::Expression
		{
			pgs::meta::CategoryCPtr _metaCategory;
			std::string _alias;

		public:
			Category();
			Category(pgs::meta::CategoryCPtr cat, const std::string &alias="");

			pgs::meta::CategoryCPtr meta() const;
			const std::string &alias() const;
		};
		typedef boost::shared_ptr<Category> Category_ptr;
	}
}

#endif
