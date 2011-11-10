#include "stdafx.h"
#include "pgs/category.hpp"
#include "impl/access.hpp"
#include "impl/category.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Category::Category(pgs::meta::CategoryCPtr cat, const std::string &alias)
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Category(cat, alias))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::CategoryCPtr Category::meta() const
	{
		return static_cast<impl::Category *>(_impl.get())->meta();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Category::alias() const
	{
		return static_cast<impl::Category *>(_impl.get())->alias();
	}


}

