#ifndef _NET_IACCEPTOR_HPP_
#define _NET_IACCEPTOR_HPP_

#include "pluma/pluma.hpp"
#include "net/ichannel.hpp"
#include "async/result.hpp"

namespace net
{
	//////////////////////////////////////////////////////////////////////////
	struct IAcceptor
	{
		virtual ~IAcceptor(){}

		virtual async::Result<boost::system::error_code> listen(const char *host, const char *service) =0;
		virtual async::Result2<boost::system::error_code, IChannelPtr> accept() =0;
		virtual void unlisten() =0;
	};
	typedef boost::shared_ptr<IAcceptor> IAcceptorPtr;

	PLUMA_PROVIDER_HEADER(IAcceptor, 1, 1);
}
#endif
