#ifndef _PGC_CONNECTIONHOLDER_HPP_
#define _PGC_CONNECTIONHOLDER_HPP_

#include "pgc/iconnection.hpp"
#include <boost/enable_shared_from_this.hpp>
#include "connectionPrepareds.hpp"
#include "bindData.hpp"

namespace pgc
{
	using namespace boost;


	class Db;
	typedef shared_ptr<Db> DbPtr;

	//////////////////////////////////////////////////////////////////////////
	class ConnectionHolder
		: public IConnection
		, public enable_shared_from_this<ConnectionHolder>
	{
		DbPtr _db;
		ConnectionPreparedsPtr _con;

		typedef function<void (IResultPtrs)> TDone;
		void keeper(TDone done, IResultPtrs result);

		static void onEndWork(DbPtr db, ConnectionPreparedsPtr con, IResultPtrs result);

	public:
		ConnectionHolder(DbPtr db, ConnectionPreparedsPtr con);
		~ConnectionHolder();

		virtual void exec(const std::string &sql,
			TDone done);

		virtual void exec(IStatementPtr s,
			TDone done);

		virtual void exec(IStatementPtr s,
			const utils::Variant &data,
			TDone done);

		virtual EConnectionStatus status();
	};
	typedef shared_ptr<ConnectionHolder> ConnectionHolderPtr;
}

#endif

