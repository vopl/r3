#ifndef _NET_SERVERSESSIONIMPL_HPP_
#define _NET_SERVERSESSIONIMPL_HPP_

#include "net/serverSession.hpp"
#include "channelHubImpl.hpp"

namespace net
{
	class ServerSessionImpl;
	typedef boost::shared_ptr<ServerSessionImpl> ServerSessionImplPtr;

	class ServerSessionImpl
		: public ChannelHubImpl
	{
		TServerSid		_sid;
	public:
		ServerSessionImpl(TServerSid sid);

		TServerSid sid();
	};
}
#endif
