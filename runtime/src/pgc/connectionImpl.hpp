#ifndef _PGC_CONNECTIONIMPL_HPP_
#define _PGC_CONNECTIONIMPL_HPP_

#include "pgc/connection.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <libpq-fe.h>

namespace pgc
{
	class ConnectionImpl
		: public boost::enable_shared_from_this<ConnectionImpl>
	{
		PGconn *	_pgcon;
		friend class StatementImpl;
	public:
		ConnectionImpl();
		~ConnectionImpl();

		PGconn *pgcon();

		EConnectionStatus open(const char *conninfo);
		EConnectionStatus reset();
		void close();
		EConnectionStatus status();

		StatementImplPtr once();
		StatementImplPtr prep();
	};

	typedef boost::shared_ptr<ConnectionImpl> ConnectionImplPtr;
	typedef boost::weak_ptr<ConnectionImpl> ConnectionImplWtr;
}
#endif
