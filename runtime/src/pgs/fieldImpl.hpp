#ifndef _PGS_FIELDIMPL_HPP_
#define _PGS_FIELDIMPL_HPP_

#include "exprImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class FieldImpl
		: public ExprImpl
	{

		// 		string _table;
		// 		string _name;
	public:
		FieldImpl(const char *field, const char *table, const char *schema, const char *tableId=NULL);
		~FieldImpl();
	};

}
#endif
