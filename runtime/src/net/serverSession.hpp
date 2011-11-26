#ifndef _NET_SERVERSESSION_HPP_
#define _NET_SERVERSESSION_HPP_

#include "net/iserverSession.hpp"
#include "channelHub.hpp"

namespace net
{
	class ServerSession;
	typedef boost::shared_ptr<ServerSession> ServerSessionPtr;

	class ServerSession
		: public ChannelHub<IServerSession>
	{
		TServerSid		_sid;
	public:
		ServerSession(TServerSid sid);

		TServerSid sid();
	};
}
#endif
