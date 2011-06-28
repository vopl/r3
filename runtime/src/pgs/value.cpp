#include "pgs/value.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Value<CppType>::Value(const CppType *v, int dataMode)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	void Value<CppType>::set(const CppType *v, int dataMode)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Value<CppType>::Value(const CppType &v, int dataMode)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	void Value<CppType>::set(const CppType &v, int dataMode)
	{

	}

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Value<CppType>::~Value()
	{

	}
}

#include "instantiate4pgctypes.hpp"
INSTANTIATE4PGCTYPES(pgs::Value)
