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
	typedef boost::shared_ptr<Db> DbPtr;

	//////////////////////////////////////////////////////////////////////////
	class ConnectionHolder
		: public IConnection
		, public enable_shared_from_this<ConnectionHolder>
	{
		DbPtr _db;
		ConnectionPreparedsPtr _con;

		typedef boost::function<void (IResultPtr)> TDone;
		void keeper(TDone done, IResultPtr result);

		static void onEndWork(DbPtr db, ConnectionPreparedsPtr con);

	public:
		ConnectionHolder(DbPtr db, ConnectionPreparedsPtr con);
		~ConnectionHolder();

		virtual void exec(const std::string &sql,
			boost::function<void (IResultPtr)> done);

		virtual void exec(IStatementPtr s,
			boost::function<void (IResultPtr)> done);

		virtual void exec(IStatementPtr s,
			const utils::Variant &data,
			boost::function<void (IResultPtr)> done);

		virtual EConnectionStatus status();

		virtual void close();
	};
	typedef boost::shared_ptr<ConnectionHolder> ConnectionHolderPtr;
}

#endif

