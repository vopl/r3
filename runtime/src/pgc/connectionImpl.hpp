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

		bool _integerDatetimes;

		std::ostream *_log;
		int _logFlags;

	public:
		ConnectionImpl();
		~ConnectionImpl();

		PGconn *pgcon();
		bool integerDatetimes();

		void log(std::ostream &out, int flags);
		EConnectionStatus open(const char *conninfo);
		EConnectionStatus ping(bool forceReset);
		void close();
		EConnectionStatus status();

		StatementImplPtr once();
		StatementImplPtr prep();

		void doLogExec(const std::string &stmt);
		void doLogError(const std::string &stmt, PGresult *res);
	private:
		static void noticeReceiver(void *arg, const PGresult *res);
		void updateLog();
	};

	typedef boost::shared_ptr<ConnectionImpl> ConnectionImplPtr;
	typedef boost::weak_ptr<ConnectionImpl> ConnectionImplWtr;
}
#endif
