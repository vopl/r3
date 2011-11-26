#ifndef _NET_ICONNECTOR_HPP_
#define _NET_ICONNECTOR_HPP_

#include "async/iservice.hpp"
#include "net/ichannel.hpp"

namespace net
{
	struct IConnector
	{
		virtual void initialize(async::IServicePtr asrv) =0;

		virtual void listen(
			const char *host, const char *service,
			boost::function<void (IChannelPtr)> ok,
			boost::function<void (boost::system::error_code)> fail) =0;

		virtual bool unlisten(const char *host, const char *service) =0;

		virtual void connect(
			const char *host, const char *service,
			boost::function<void (IChannelPtr)> ok,
			boost::function<void (boost::system::error_code)> fail) =0;
	};
	typedef boost::shared_ptr<IConnector> IConnectorPtr;

	PLUMA_PROVIDER_HEADER(IConnector, 1, 1);

}
#endif
