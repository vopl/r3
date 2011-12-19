#include "pch.h"
#include "connectionHolder.hpp"
#include "db.hpp"

namespace pgc
{
// 	//////////////////////////////////////////////////////////////////////////
// 	void ConnectionHolder::onEndWork(DbPtr db, ConnectionImplPtr impl, IResultPtrs /*result*/)
// 	{
// 		db->unwork(impl);
// 	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionHolder::ConnectionHolder(DbPtr db, ConnectionImplPtr impl)
		: _db(db)
		, _impl(impl)
	{
// 		_con->beginWork();
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionHolder::~ConnectionHolder()
	{
		_db->unwork(_impl);

// 		TDone done = 
// 			bind(&ConnectionHolder::onEndWork, 
// 				_db, _con, _1);
// 
// 		_con->dispatch(
// 			bind(&ConnectionPrepareds::endWork, _con, 
// 				done));
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> ConnectionHolder::query(const std::string &sql)
	{
		async::Result<IResultPtrs> res;
		_impl->runQuery(res, sql);
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> ConnectionHolder::query(IStatementPtr s)
	{
		async::Result<IResultPtrs> res;
		_impl->runQueryWithPrepare(res, s, BindDataPtr());
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	async::Result<IResultPtrs> ConnectionHolder::query(IStatementPtr s, const utils::Variant &data)
	{
		async::Result<IResultPtrs> res;
		_impl->runQueryWithPrepare(res, s, BindDataPtr(new BindData(data, _impl)));
		return res;
	}

	//////////////////////////////////////////////////////////////////////////
	EConnectionStatus ConnectionHolder::status()
	{
		return _impl->status();
	}

}
