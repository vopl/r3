#ifndef _SERVER_ISERVER_HPP_
#define _SERVER_ISERVER_HPP_

#include "async/iservice.hpp"
#include "pgc/idb.hpp"

namespace server
{
	struct IServer
	{
		virtual ~IServer(){}

		virtual bool start(pluma::Pluma *plugs, const char *host, const char *service) =0;
		virtual void stop() =0;
		
		virtual pluma::Pluma * getPlugs() =0;
		virtual async::IServicePtr getAsync() =0;
		virtual pgc::IDbPtr getDb() =0;
	};
	typedef boost::shared_ptr<IServer> IServerPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(IServer, 1, 1);

}
#endif
