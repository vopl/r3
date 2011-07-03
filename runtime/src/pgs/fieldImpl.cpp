#include "fieldImpl.hpp"
#include "statementImpl.hpp"

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
		s->regField(boost::shared_static_cast<FieldImpl>(shared_from_this()));
	}

	//////////////////////////////////////////////////////////////////////////
	void FieldImpl::mkSql(std::string &result)
	{
		result += _field;
	}

}
