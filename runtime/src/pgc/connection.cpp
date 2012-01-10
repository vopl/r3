#include "pch.h"
#include "pgc/connection.hpp"
#include "bindData.hpp"
#include "connectionImpl.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	Connection::Connection()
		: _impl()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Connection::~Connection()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	Connection::operator bool() const
	{
		return _impl?true:false;
	}

	//////////////////////////////////////////////////////////////////////////
	bool Connection::operator!() const
	{
		return _impl?false:true;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<Datas> Connection::query(const char *sql)
	{
		return query(std::string(sql));
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<Datas> Connection::query(const char *sql, const utils::Variant &data)
	{
		return query(std::string(sql), data);
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<Datas> Connection::query(const std::string &sql)
	{
		async::Result<Datas> res;
		_impl->_holder->runQuery(res, sql, BindDataPtr());
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<Datas> Connection::query(const std::string &sql, const utils::Variant &data)
	{
		async::Result<Datas> res;
		_impl->_holder->runQuery(res, sql, BindDataPtr(new BindData(data, _impl->_holder)));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<Datas> Connection::query(Statement s, bool withPrepare)
	{
		async::Result<Datas> res;
		if(withPrepare)
		{
			_impl->_holder->runQueryWithPrepare(res, s, BindDataPtr());
		}
		else
		{
			_impl->_holder->runQuery(res, s.getSql(), BindDataPtr());
		}
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<Datas> Connection::query(Statement s, const utils::Variant &data, bool withPrepare)
	{
		async::Result<Datas> res;

		BindDataPtr bindData(new BindData(data, _impl->_holder));
		if(withPrepare)
		{
			_impl->_holder->runQueryWithPrepare(res, s, bindData);
		}
		else
		{
			_impl->_holder->runQuery(res, s.getSql(), bindData);
		}
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	EConnectionStatus Connection::status()
	{
		return _impl?_impl->_holder->status():ecsNull;
	}

}
