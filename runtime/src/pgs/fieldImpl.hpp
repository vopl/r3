#ifndef _PGS_FIELDIMPL_HPP_
#define _PGS_FIELDIMPL_HPP_

#include "exprImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	class FieldImpl
		: public ExprImpl
	{

		std::string _field;
		std::string _table;
		std::string _schema;
		std::string _tableId;
	public:
		FieldImpl(const char *field, const char *table, const char *schema, const char *tableId=NULL);
		~FieldImpl();

		virtual void reg(StatementImpl *s);
		virtual void mkSql(std::string &result);
	};

	typedef boost::shared_ptr<FieldImpl> FieldImpl_ptr;

}
#endif