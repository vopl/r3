#include "pgs/field.hpp"
#include "fieldImpl.hpp"
#include "exprAccess.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	Field::Field(const char *field, const char *table, const char *schema, const char *tableId)
		: Expr(ExprAccess(ExprImpl_ptr(new FieldImpl(field, table, schema, tableId))))
	{

	}
	
	//////////////////////////////////////////////////////////////////////////
	Field::~Field()
	{

	}

}

