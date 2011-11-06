#include "stdafx.h"
#include "pgs/value.hpp"
#include "impl/value.hpp"
#include "impl/access.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Value::Value()
		: Expression(impl::Access<Expression>(impl::Expression_ptr(new impl::Value())))
	{
		assert(0);
	}



	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Value::Value(const CppType *v, EValueDataMode vdm)
		: Expression(impl::Access<Expression>(impl::Expression_ptr(new impl::Value(v,vdm))))
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	void Value::set(const CppType *v, EValueDataMode vdm)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Value::Value(const CppType &v, EValueDataMode vdm)
		: Expression(impl::Access<Expression>(impl::Expression_ptr(new impl::Value(v, vdm))))
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	void Value::set(const CppType &v, EValueDataMode vdm)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	Value::~Value()
	{

	}
}

#include "pgc/cppDataType.hpp"

#define INST_METHOD template pgs::Value::Value(const PGCTYPE *v, EValueDataMode vdm);
#include "instantiate4pgctypes.hpp"
#define INST_METHOD template void pgs::Value::set(const PGCTYPE *v, EValueDataMode vdm);
#include "instantiate4pgctypes.hpp"

#define INST_METHOD template pgs::Value::Value(const PGCTYPE &v, EValueDataMode vdm);
#include "instantiate4pgctypes.hpp"
#define INST_METHOD template void pgs::Value::set(const PGCTYPE &v, EValueDataMode vdm);
#include "instantiate4pgctypes.hpp"
