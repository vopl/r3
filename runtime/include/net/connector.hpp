#ifndef _NET_CONNECTOR_HPP_
#define _NET_CONNECTOR_HPP_

#include "net/channel.hpp"
#include "async/service.hpp"

namespace net
{
	class ConnectorImpl;
	class Connector
	{
	protected:
		typedef boost::shared_ptr<ConnectorImpl> ImplPtr;
		ImplPtr _impl;

	public:
		Connector(async::Service asrv);

		void listen(
			const char *host, const char *service,
			boost::function<void (Channel)> ok,
			boost::function<void (boost::system::error_code)> fail);

		bool unlisten(const char *host, const char *service);

		void connect(
			const char *host, const char *service,
			boost::function<void (Channel)> ok,
			boost::function<void (boost::system::error_code)> fail);
	};
}
#endif
