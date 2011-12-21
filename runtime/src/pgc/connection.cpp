#include "pch.h"
#include "connection.hpp"
#include "db.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	Connection::Connection(DbPtr db, ConnectionImplPtr impl)
		: _db(db)
		, _impl(impl)
	{
 		_impl->beginWork();
	}

	//////////////////////////////////////////////////////////////////////////
	Connection::~Connection()
	{
		async::Result<IResultPtrs> res;
		_impl->runEndWork(res);
		res.wait();
		_db->unwork(_impl);
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> Connection::query(const std::string &sql)
	{
		async::Result<IResultPtrs> res;
		_impl->runQuery(res, sql);
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> Connection::query(IStatementPtr s)
	{
		async::Result<IResultPtrs> res;
		_impl->runQueryWithPrepare(res, s, BindDataPtr());
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> Connection::query(IStatementPtr s, const utils::Variant &data)
	{
		async::Result<IResultPtrs> res;
		_impl->runQueryWithPrepare(res, s, BindDataPtr(new BindData(data, _impl)));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	EConnectionStatus Connection::status()
	{
		return _impl->status();
	}

}
