#ifndef _PGC_DB_HPP_
#define _PGC_DB_HPP_

#include "pgc/idb.hpp"
#include <boost/enable_shared_from_this.hpp>

namespace pgc
{
	using namespace boost;

	class Db
		: public IDb
		, public enable_shared_from_this<Db>
	{
	public:
		Db();
		~Db();

		virtual void initialize(
			async::IServicePtr asrv,
			const char *conninfo,
			size_t maxConnections,
			function<void (size_t)> connectionMade,
			function<void (size_t)> connectionLost);

		virtual void allocConnection(function<void (IConnectionPtr)> ready);

		virtual void deinitialize();
	};

	PLUMA_INHERIT_PROVIDER(Db, IDb);
}

#endif

