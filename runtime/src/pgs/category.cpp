#include "pch.h"
#include "pgs/category.hpp"
#include "implAccess.hpp"
#include "categoryImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Category::Category(pgs::meta::CategoryCPtr cat, const std::string &alias)
		: Expression(ImplAccess<Expression>(ImplPtr(new CategoryImpl(cat, alias))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::CategoryCPtr Category::meta() const
	{
		return static_cast<CategoryImpl *>(_impl.get())->meta();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Category::alias() const
	{
		return static_cast<CategoryImpl *>(_impl.get())->alias();
	}


}

