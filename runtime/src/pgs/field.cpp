#include "pgs/field.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Field<CppType>::Field(const char *field, const char *table, const char *schema, const char *tableId)
	{

	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	Field<CppType>::~Field()
	{

	}

}

#include "instantiate4pgctypes.hpp"
INSTANTIATE4PGCTYPES(pgs::Field)
