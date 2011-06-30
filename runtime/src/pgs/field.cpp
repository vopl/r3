#include "pgs/field.hpp"
#include "fieldImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Field::Field(const char *field, const char *table, const char *schema, const char *tableId)
		: Expr(ExprImpl_ptr(new FieldImpl(field, table, schema, tableId)))
	{

	}
	
	//////////////////////////////////////////////////////////////////////////
	Field::~Field()
	{

	}

}

