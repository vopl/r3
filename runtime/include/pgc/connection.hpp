#ifndef _PGC_CONNECTION_HPP_
#define _PGC_CONNECTION_HPP_

#include "pgc/statement.hpp"
#include <ostream>
namespace pgc
{
	class ConnectionImpl;

	enum EConnectionStatus
	{
		ecs_null,
		ecs_ok,
		ecs_lost,
	};

	enum ELogFlags
	{
		lf_none		= 0x00,

		lf_notice	= 0x01,
		lf_exec		= 0x02,

		lf_all		= 0x03,
	};

	//////////////////////////////////////////////////////////////////////////
	class Connection
	{
	protected:
		friend class Blob;
		typedef boost::shared_ptr<ConnectionImpl> ImplPtr;
		ImplPtr _impl;

	public:
		Connection();
		~Connection();

		void log(std::ostream &out, int flags = lf_notice);

		EConnectionStatus open(const char *conninfo);
		EConnectionStatus ping(bool forceReset = false);
		void close();
		EConnectionStatus status();

		Statement once(const char *sql=NULL);
		Statement prep(const char *sql=NULL);
		Statement once(const std::string &sql);
		Statement prep(const std::string &sql);

	};
}
#endif
