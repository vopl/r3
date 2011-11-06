#include "stdafx.h"
#include "pgs/field.hpp"
#include "impl/access.hpp"
#include "impl/field.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Field::Field()
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Field())))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Field::Field(pgs::meta::FieldCPtr fld)
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Field(fld))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	pgs::meta::FieldCPtr Field::meta() const
	{
		return static_cast<impl::Field *>(_impl.get())->meta();
	}

}
