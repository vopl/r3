#ifndef _SERVER_ISERVER_HPP_
#define _SERVER_ISERVER_HPP_

#include "pluma/pluma.hpp"
#include <boost/shared_ptr.hpp>
#include "async/iservice.hpp"


namespace server
{
	struct IServer
	{
		virtual void run(pluma::Pluma *plugs, const char *host, const char *service) =0;
		
		virtual pluma::Pluma * getPlugs() =0;
		virtual async::IServicePtr getAsync() =0;
	};
	typedef boost::shared_ptr<IServer> IServerPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(IServer, 1, 1);

}
#endif
