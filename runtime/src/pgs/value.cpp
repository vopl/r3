#include "pgs/value.hpp"
#include "valueImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Value::Value()
		: Expr(ExprImpl_ptr(new ValueImpl()))
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Value::Value(const CppType *v, int dataMode)
		: Expr(ExprImpl_ptr(new ValueImpl(v, dataMode)))
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	void Value::set(const CppType *v, int dataMode)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Value::Value(const CppType &v, int dataMode)
		: Expr(ExprImpl_ptr(new ValueImpl(v, dataMode)))
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	void Value::set(const CppType &v, int dataMode)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	Value::~Value()
	{

	}
}

#include "pgc/cppDataType.hpp"

#define INST_METHOD template pgs::Value::Value(const PGCTYPE *v, int dataMode);
#include "instantiate4pgctypes.hpp"
#define INST_METHOD template void pgs::Value::set(const PGCTYPE *v, int dataMode);
#include "instantiate4pgctypes.hpp"

#define INST_METHOD template pgs::Value::Value(const PGCTYPE &v, int dataMode);
#include "instantiate4pgctypes.hpp"
#define INST_METHOD template void pgs::Value::set(const PGCTYPE &v, int dataMode);
#include "instantiate4pgctypes.hpp"
