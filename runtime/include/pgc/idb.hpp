#ifndef _PGC_IDB_HPP_
#define _PGC_IDB_HPP_

#include "async/iservice.hpp"
#include "pgc/iconnection.hpp"
#include "pluma/pluma.hpp"
#include "async/result.hpp"


namespace pgc
{
	//////////////////////////////////////////////////////////////////////////
	struct IDb
	{
		virtual ~IDb(){}

		virtual void initialize(
			async::IServicePtr asrv,
			const char *conninfo,
			size_t maxConnections,
			boost::function<void (size_t)> connectionMade,
			boost::function<void (size_t)> connectionLost) =0;

		//virtual void allocConnection(boost::function<void (IConnectionPtr)> ready) =0;
		virtual async::Result<IConnectionPtr> allocConnection()=0;

		virtual void deinitialize() =0;
	};
	typedef boost::shared_ptr<IDb> IDbPtr;

	PLUMA_PROVIDER_HEADER(IDb, 1, 1);
}
#endif
