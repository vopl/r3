#include "statementImpl.hpp"
#include <boost/foreach.hpp>

namespace pgs
{
	//////////////////////////////////////////////////////////////////////////
	StatementImpl::StatementImpl()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	StatementImpl::~StatementImpl()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	void StatementImpl::addExpr(const ExprImpl_ptr &e)
	{
		_exprs.insert(e);
	}

	//////////////////////////////////////////////////////////////////////////
	void StatementImpl::compile()
	{
		_values.clear();
		_fields.clear();

		BOOST_FOREACH(const ExprImpl_ptr &e, _exprs)
		{
			e->reg(this);
		}

		BOOST_FOREACH(const ExprImpl_ptr &e, _exprs)
		{
			std::string sql;
			e->mkSql(sql);
			//std::cout<<sql<<std::endl;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void StatementImpl::regValue(const ValueImpl_ptr &v)
	{
		if(_values.end() == _values.find(v))
		{
			_values.insert(v);
			v->setNumber(_values.size());
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void StatementImpl::regField(const FieldImpl_ptr &f)
	{
		if(_fields.end() == _fields.find(f))
		{
			_fields.insert(f);
		}
	}
}
