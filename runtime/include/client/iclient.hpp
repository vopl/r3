#ifndef _CLIENT_ICLIENT_HPP_
#define _CLIENT_ICLIENT_HPP_

#include "client/isession.hpp"
#include "async/result.hpp"

namespace client
{
	struct IClient
	{
		virtual ~IClient(){}

		virtual void start(pluma::Pluma *plugs) =0;
		virtual async::Result2<boost::system::error_code, ISessionPtr> 
			createSession(const char *host, const char *service) =0;
		virtual pluma::Pluma * getPlugs() =0;
		virtual void stop() =0;
	};
	typedef boost::shared_ptr<IClient> IClientPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(IClient, 1, 1);

}
#endif
