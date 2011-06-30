#include "pgs/value.hpp"
#include "valueImpl.hpp"

namespace pgs
{
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
