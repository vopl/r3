#include "stdafx.h"
#include "pgs/category.hpp"
#include "impl/access.hpp"
#include "impl/category.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Category::Category()
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Category())))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Category::Category(pgs::meta::CategoryCPtr cat)
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Category(cat))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::CategoryCPtr Category::meta() const
	{
		return static_cast<impl::Category *>(_impl.get())->meta();
	}

}

