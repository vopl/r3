#include "pch.h"
#include "pgs/field.hpp"
#include "implAccess.hpp"
#include "fieldImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Field::Field(pgs::meta::FieldCPtr fld, const std::string &alias)
		: Expression(ImplAccess<Expression>(ImplPtr(new FieldImpl(fld, alias))))
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Field::Field(const std::string &srcAlias, pgs::meta::FieldCPtr fld, const std::string &alias)
		: Expression(ImplAccess<Expression>(ImplPtr(new FieldImpl(srcAlias, fld, alias))))
	{

	}


	//////////////////////////////////////////////////////////////////////////
	pgs::meta::FieldCPtr Field::meta() const
	{
		return static_cast<FieldImpl *>(_impl.get())->meta();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Field::srcAlias() const
	{
		return static_cast<FieldImpl *>(_impl.get())->srcAlias();
	}

	//////////////////////////////////////////////////////////////////////////
	const std::string &Field::alias() const
	{
		return static_cast<FieldImpl *>(_impl.get())->alias();
	}

}
