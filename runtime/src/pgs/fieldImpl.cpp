#include "fieldImpl.hpp"

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	FieldImpl::FieldImpl(const char *field, const char *table, const char *schema, const char *tableId)
		: _field(field)
		, _table(table)
		, _schema(schema)
		, _tableId(tableId?tableId:table)
	{
	}
	
	//////////////////////////////////////////////////////////////////////////
	FieldImpl::~FieldImpl()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	void FieldImpl::reg(StatementImpl *s)
	{
		assert(0);
	}

	//////////////////////////////////////////////////////////////////////////
	void FieldImpl::mkSql(std::string &result)
	{
		result += _field;
	}

}
