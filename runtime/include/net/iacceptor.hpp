#ifndef _NET_IACCEPTOR_HPP_
#define _NET_IACCEPTOR_HPP_

#include "pluma/pluma.hpp"
#include "net/ichannel.hpp"
#include "async/future.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	struct IAcceptor
	{
		virtual ~IAcceptor(){}

		virtual async::Future<boost::system::error_code> listen(
				const boost::function<void(boost::system::error_code, IChannelPtr)> &onAccept,
			const char *host, const char *service, bool useSsl=false) =0;
		virtual void unlisten() =0;
	};
	typedef boost::shared_ptr<IAcceptor> IAcceptorPtr;

	PLUMA_PROVIDER_HEADER(IAcceptor, 1, 1)
}
#endif
