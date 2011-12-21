#ifndef _CLIENT_ICLIENT_HPP_
#define _CLIENT_ICLIENT_HPP_

#include "client/isession.hpp"

namespace client
{
	struct IClient
	{
		virtual ~IClient(){}

		virtual void start(
			pluma::Pluma *plugs,
			boost::function<void (ISessionPtr)> onSessionStart,
			boost::function<void (ISessionPtr)> onSessionStop,
			boost::function<void (size_t numChannels, boost::system::error_code ec)> onChannelChange) =0;

		virtual void connect(const char *host, const char *service) =0;
		
		virtual pluma::Pluma * getPlugs() =0;

		virtual void stop() =0;
	};
	typedef boost::shared_ptr<IClient> IClientPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_PROVIDER_HEADER(IClient, 1, 1);

}
#endif
