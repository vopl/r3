#ifndef _PGC_CONNECTIONIMPL_HPP_
#define _PGC_CONNECTIONIMPL_HPP_

#include "statementImpl.hpp"
#include "pgc/connection.hpp"

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

		EConnectionStatus open(const char *conninfo);
		void close();
		EConnectionStatus status();

		StatementImplPtr once();
		StatementImplPtr prep();
	};

	typedef boost::shared_ptr<ConnectionImpl> ConnectionImplPtr;
	typedef boost::weak_ptr<ConnectionImpl> ConnectionImplWtr;
}
#endif
