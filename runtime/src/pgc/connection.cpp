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
	async::Future<Datas> Connection::query(const char *sql)
	{
		return query(std::string(sql));
	}

	//////////////////////////////////////////////////////////////////////////
	async::Future<Datas> Connection::query(const char *sql, const utils::Variant &data)
	{
		return query(std::string(sql), data);
	}

	//////////////////////////////////////////////////////////////////////////
	async::Future<Datas> Connection::query(const std::string &sql)
	{
		async::Future<Datas> res;
		_impl->_holder->runQuery(res, sql, BindDataPtr());
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Future<Datas> Connection::query(const std::string &sql, const utils::Variant &data)
	{
		async::Future<Datas> res;
		_impl->_holder->runQuery(res, sql, BindDataPtr(new BindData(data, _impl->_holder)));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Future<Datas> Connection::query(Statement s, bool withPrepare)
	{
		async::Future<Datas> res;
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
	async::Future<Datas> Connection::query(Statement s, const utils::Variant &data, bool withPrepare)
	{
		async::Future<Datas> res;

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
