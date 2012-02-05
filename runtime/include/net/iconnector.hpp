#ifndef _NET_ICONNECTOR_HPP_
#define _NET_ICONNECTOR_HPP_

#include "pluma/pluma.hpp"
#include "net/ichannel.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	struct IConnector
	{
		virtual ~IConnector(){}
		virtual async::Future2<boost::system::error_code, IChannelPtr> connect(const char *host, const char *service, bool useSsl=false) =0;
	};
	typedef boost::shared_ptr<IConnector> IConnectorPtr;

	PLUMA_PROVIDER_HEADER(IConnector, 1, 1);

}
#endif
