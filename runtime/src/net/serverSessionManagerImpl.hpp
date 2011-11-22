#ifndef _NET_SERVERSESSIONMANAGER_HPP_
#define _NET_SERVERSESSIONMANAGER_HPP_

#include "net/serverSession.hpp"

namespace net
{
	typedef int TSid;
	class ServerSessionManagerImpl;
	class ServerSessionManager
	{
	protected:
		typedef boost::shared_ptr<ServerSessionManagerImpl> ImplPtr;
		ImplPtr _impl;

	public:
		ServerSessionManager(Connector con);

		void start(
			const char *host, const char *service,
			boost::function<void (ServerSession)> ready,
			boost::function<void (system::error_code)> fail);

		void stop();
	};
}
#endif
