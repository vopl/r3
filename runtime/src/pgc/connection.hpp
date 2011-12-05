#ifndef _PGC_CONNECTION_HPP_
#define _PGC_CONNECTION_HPP_

#include "pgc/iconnection.hpp"
#include <boost/enable_shared_from_this.hpp>
#include "pgconnWrapper.hpp"

namespace pgc
{
	using namespace boost;


	class Db;
	typedef boost::shared_ptr<Db> DbPtr;

	//////////////////////////////////////////////////////////////////////////
	class Connection
		: public IConnection
		, public enable_shared_from_this<Connection>
	{
		DbPtr _db;
		PGconnWrapperPtr _con;

	public:
		Connection(DbPtr db, PGconnWrapperPtr con);
		~Connection();

		virtual void exec(IStatementPtr s,
			function<void (IResultPtr)> done);
	};
	typedef boost::shared_ptr<Connection> ConnectionPtr;
}

#endif

