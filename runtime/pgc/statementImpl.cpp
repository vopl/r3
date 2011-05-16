#include "stdafx.h"

#include "statementImpl.hpp"
#include "connectionImpl.hpp"

namespace pgc
{
	StatementImpl::StatementImpl(ConnectionImplPtr con, bool once)
		: _con(con)
		, _once(once)
	{

	}
	StatementImpl::~StatementImpl()
	{
		_con.reset();
	}

	void StatementImpl::sql(const char *csz)
	{
		_sql = csz;
	}
	void StatementImpl::bind(int typIdx, void const *data, size_t idx)
	{
		if(!idx)
		{
			_binds.push_back(CppConstValue(typIdx, data));
		}
		else
		{
			if(idx >= _binds.size())
			{
				_binds.resize(idx+1);
			}
			_binds[idx] = CppConstValue(typIdx, data);
		}
	}
	ResultImplPtr StatementImpl::exec()
	{
		if(_once)
		{
			if(_binds.size())
			{
				assert(!"bind");
			}
			else
			{
				//return ResultImplPtr(new ResultImpl(PQexec(_con->_pgcon, _sql.c_str())));
				return ResultImplPtr(new ResultImpl(PQexecParams(_con->_pgcon, _sql.c_str(), 0, 0, 0, 0, 0, 1)));
			}
		}
		else
		{
			if(_binds.size())
			{
				assert(!"bind");
			}
			else
			{
				assert(!"exec");
			}
		}

		assert(!"never here");
		return ResultImplPtr();
	}
}