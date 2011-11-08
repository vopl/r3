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
	Field::Field(const std::string &srcAlias, pgs::meta::FieldCPtr fld)
		: Expression(impl::Access<Expression>(Impl_ptr(new impl::Field(srcAlias, fld))))
	{

	}


	//////////////////////////////////////////////////////////////////////////
	pgs::meta::FieldCPtr Field::meta() const
	{
		return static_cast<impl::Field *>(_impl.get())->meta();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Field::srcAlias() const
	{
		return static_cast<impl::Field *>(_impl.get())->srcAlias();
	}


}
