#ifndef _NET_CONNECTOR_HPP_
#define _NET_CONNECTOR_HPP_

#include "net/channel.hpp"
#include "net/asyncService.hpp"
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
#include <boost/system/error_code.hpp>

namespace net
{
	class ConnectorImpl;
	class Connector
	{
	protected:
		typedef boost::shared_ptr<ConnectorImpl> ImplPtr;
		ImplPtr _impl;

	public:
		Connector(AsyncService &asrv);

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
