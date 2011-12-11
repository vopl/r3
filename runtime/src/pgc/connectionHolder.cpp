#include "pch.h"
#include "connectionHolder.hpp"
#include "db.hpp"

namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::keeper(TDone done, IResultPtrs result)
	{
		if(done)
		{
			done(result);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::onEndWork(DbPtr db, ConnectionPreparedsPtr con, IResultPtrs /*result*/)
	{
		db->unwork(con);
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionHolder::ConnectionHolder(DbPtr db, ConnectionPreparedsPtr con)
		: _db(db)
		, _con(con)
	{
		_con->beginWork();
	}

	//////////////////////////////////////////////////////////////////////////
	ConnectionHolder::~ConnectionHolder()
	{
		TDone done = 
			bind(&ConnectionHolder::onEndWork, 
				_db, _con, _1);

		_con->dispatch(
			bind(&ConnectionPrepareds::endWork, _con, 
				done));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::query(const std::string &sql,
		TDone done)
	{
		TDone keepedDone = 
			bind(&ConnectionHolder::keeper, shared_from_this(), 
				done, _1);

		_con->dispatch(
			bind(&ConnectionProcessor::runQuery, _con, 
				sql, keepedDone));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::query(IStatementPtr s,
		TDone done)
	{
		TDone keepedDone = 
			bind(&ConnectionHolder::keeper, shared_from_this(), 
				done, _1);

		BindDataPtr nullBindData;

		_con->dispatch(
			bind(&ConnectionPrepareds::runQueryWithPrepare, _con, 
				s, nullBindData, keepedDone));
	}

	//////////////////////////////////////////////////////////////////////////
	void ConnectionHolder::query(IStatementPtr s,
		const utils::Variant &data,
		TDone done)
	{
		TDone keepedDone = 
			bind(&ConnectionHolder::keeper, shared_from_this(), 
			done, _1);

		BindDataPtr bindData(new BindData(data, _con));

		_con->dispatch(
			bind(&ConnectionPrepareds::runQueryWithPrepare, _con, 
			s, bindData, keepedDone));
	}

	//////////////////////////////////////////////////////////////////////////
	EConnectionStatus ConnectionHolder::status()
	{
		return _con->status();
	}

}
