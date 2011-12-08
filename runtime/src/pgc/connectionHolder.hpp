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

		//void keeper();

	public:
		ConnectionHolder(DbPtr db, ConnectionPreparedsPtr con);
		~ConnectionHolder();

		virtual void exec(const char *sql,
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

