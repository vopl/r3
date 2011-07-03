#include "pgs/value.hpp"
#include "valueImpl.hpp"
#include "exprAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Value::Value(const char *name)
		: Expr(ExprAccess(ExprImpl_ptr(new ValueImpl(name))))
	{

	}



	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Value::Value(const char *name, const CppType *v, int dataMode)
		: Expr(ExprAccess(ExprImpl_ptr(new ValueImpl(name, v, dataMode))))
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	void Value::set(const CppType *v, int dataMode)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Value::Value(const char *name, const CppType &v, int dataMode)
		: Expr(ExprAccess(ExprImpl_ptr(new ValueImpl(name, v, dataMode))))
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

	//////////////////////////////////////////////////////////////////////////
	AValue::AValue()
		: Value("")
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	AValue::AValue(const CppType *v, int dataMode)
		: Value("", v, dataMode)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	AValue::AValue(const CppType &v, int dataMode)
		: Value("", v, dataMode)
	{

	}

}

#include "pgc/cppDataType.hpp"

#define INST_METHOD template pgs::Value::Value(const char *name, const PGCTYPE *v, int dataMode);
#include "instantiate4pgctypes.hpp"
#define INST_METHOD template void pgs::Value::set(const PGCTYPE *v, int dataMode);
#include "instantiate4pgctypes.hpp"

#define INST_METHOD template pgs::Value::Value(const char *name, const PGCTYPE &v, int dataMode);
#include "instantiate4pgctypes.hpp"
#define INST_METHOD template void pgs::Value::set(const PGCTYPE &v, int dataMode);
#include "instantiate4pgctypes.hpp"




#define INST_METHOD template pgs::AValue::AValue(const PGCTYPE *v, int dataMode);
#include "instantiate4pgctypes.hpp"

#define INST_METHOD template pgs::AValue::AValue(const PGCTYPE &v, int dataMode);
#include "instantiate4pgctypes.hpp"
