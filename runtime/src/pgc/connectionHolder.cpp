#include "pch.h"
#include "connectionHolder.hpp"
#include "db.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::endWork(DbPtr db, ConnectionImplPtr impl)
	{
		async::Result<IResultPtrs> res;
		impl->runEndWork(res);
		res.wait();
		db->unwork(impl);
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionHolder::ConnectionHolder(DbPtr db, ConnectionImplPtr impl)
		: _db(db)
		, _impl(impl)
	{
 		_impl->beginWork();
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionHolder::~ConnectionHolder()
	{
		_impl->post(bind(&ConnectionHolder::endWork, _db, _impl));
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> ConnectionHolder::query(const std::string &sql)
	{
		async::Result<IResultPtrs> res;
		_impl->post(bind(&ConnectionImpl::runQuery, _impl, res, sql));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> ConnectionHolder::query(IStatementPtr s)
	{
		async::Result<IResultPtrs> res;
		_impl->post(bind(&ConnectionImpl::runQueryWithPrepare, _impl, res, s, BindDataPtr()));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> ConnectionHolder::query(IStatementPtr s, const utils::Variant &data)
	{
		async::Result<IResultPtrs> res;
		_impl->post(bind(&ConnectionImpl::runQueryWithPrepare, _impl, res, s, BindDataPtr(new BindData(data, _impl))));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	EConnectionStatus ConnectionHolder::status()
	{
		return _impl->status();
	}

}
