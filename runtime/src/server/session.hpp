#ifndef _SERVER_SESSION_HPP_
#define _SERVER_SESSION_HPP_

#include "server/isession.hpp"
#include "../net/channelHub.hpp"

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class Session;
	typedef boost::shared_ptr<Session> SessionPtr;

	//////////////////////////////////////////////////////////////////////////
	class Session
		: public net::ChannelHub<ISession>
	{
		TServerSid			_sid;
		function<void ()>	_sstop;
	public:
		Session(TServerSid sid);

		void listenStop(function<void ()> sstop);
		virtual void close();

		TServerSid sid();
	};
}
#endif
