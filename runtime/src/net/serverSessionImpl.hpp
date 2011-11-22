#ifndef _NET_SERVERSESSION_HPP_
#define _NET_SERVERSESSION_HPP_

#include "net/serverSession.hpp"

namespace net
{
	typedef int TSid;
	class ServerSessionImpl;
	class ServerSession
		: public Channel
	{
	protected:
		typedef boost::shared_ptr<ServerSessionManagerImpl> ImplPtr;

	public:
		ServerSession(Connector con);

		TSid sid();
	};
}
#endif
