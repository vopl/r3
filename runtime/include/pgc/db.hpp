#ifndef _PGC_DB_HPP_
#define _PGC_DB_HPP_

#include "async/service.hpp"
#include "pgc/connection.hpp"
#include "async/future.hpp"


namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	class DbImpl;
	typedef boost::shared_ptr<DbImpl> DbImplPtr;

	//////////////////////////////////////////////////////////////////////////
	class PG_API Db
	{
	protected:
		typedef DbImplPtr ImplPtr;
		ImplPtr	_impl;

	public:
		Db();
		Db(const char *conninfo,
			size_t maxConnections,
			boost::function<void (size_t)> connectionMade,
			boost::function<void (size_t)> connectionLost);
		~Db();

		operator bool() const;
		bool operator!() const;
		void reset();

		async::Future<Connection> allocConnection();
	};
}
#endif
