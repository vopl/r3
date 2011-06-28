#ifndef _PGS_FIELD_HPP_
#define _PGS_FIELD_HPP_

#include "pgs/expr.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class Field
		: public Expr
	{

// 		string _table;
// 		string _name;
	public:
		Field(const char *field, const char *table, const char *schema, const char *tableId=NULL);
		~Field();
	};

}
#endif
