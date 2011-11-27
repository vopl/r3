#ifndef _CLIENT_ICLIENT_HPP_
#define _CLIENT_ICLIENT_HPP_

#include "async/iservice.hpp"


namespace client
{
	struct IClient
	{
		virtual void run(pluma::Pluma *plugs, const char *host, const char *service) =0;
		
		virtual pluma::Pluma * getPlugs() =0;
		virtual async::IServicePtr getAsync() =0;

		virtual void stop() =0;
	};
	typedef boost::shared_ptr<IClient> IClientPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(IClient, 1, 1);

}
#endif
