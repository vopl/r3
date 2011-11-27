#ifndef _SERVER_SESSION_HPP_
#define _SERVER_SESSION_HPP_

#include "server/isession.hpp"
#include "../net/channelHub.hpp"

namespace server
{
	class Session;
	typedef boost::shared_ptr<Session> SessionPtr;

	class Session
		: public net::ChannelHub<ISession>
	{
		TServerSid		_sid;
	public:
		Session(TServerSid sid);

		TServerSid sid();
	};
}
#endif
