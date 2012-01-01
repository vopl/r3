#ifndef _NET_ICONNECTOR2_HPP_
#define _NET_ICONNECTOR2_HPP_

#include "pluma/pluma.hpp"
#include "net/ichannel.hpp"
#include "async/result.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	struct IConnector2
	{
		virtual ~IConnector2(){}
		virtual async::Result2<boost::system::error_code, IChannelPtr> connect(const char *host, const char *service) =0;
	};
	typedef boost::shared_ptr<IConnector2> IConnector2Ptr;
	PLUMA_PROVIDER_HEADER(IConnector2, 1, 1);
}
#endif
