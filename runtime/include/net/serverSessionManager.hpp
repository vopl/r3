#ifndef _NET_SERVERSESSIONMANAGER_HPP_
#define _NET_SERVERSESSIONMANAGER_HPP_

#include "net/serverSession.hpp"
#include "net/connector.hpp"

namespace net
{
	class ServerSessionManagerImpl;
	class ServerSessionManager
	{
	protected:
		typedef boost::shared_ptr<ServerSessionManagerImpl> ImplPtr;
		ImplPtr _impl;

	public:
		ServerSessionManager(Connector connector, const char *host, const char *service);

		void start(
			boost::function<void (ServerSession)> ready,
			boost::function<void (boost::system::error_code)> fail);

		void stop();
	};
}
#endif
