#ifndef _PGC_CONNECTION_HPP_
#define _PGC_CONNECTION_HPP_

#include "pgc/statement.hpp"

namespace pgc
{
	class ConnectionImpl;

	enum EConnectionStatus
	{
		ecs_null,
		ecs_ok,
		ecs_lost,
	};

	//////////////////////////////////////////////////////////////////////////
	class Connection
	{
		friend class Blob;
		boost::shared_ptr<ConnectionImpl> _impl;

	public:
		Connection();
		~Connection();

		EConnectionStatus open(const char *conninfo);
		EConnectionStatus ping(bool forceReset = false);
		void close();
		EConnectionStatus status();

		Statement once(const char *sql=NULL);
		Statement prep(const char *sql=NULL);
	};
}
#endif
