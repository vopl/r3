#ifndef _CLIENT_SESSION_HPP_
#define _CLIENT_SESSION_HPP_

#include "client/isession.hpp"
#include "net/channelHub.hpp"
#include "net/iconnector.hpp"

namespace client
{
	using namespace boost;
	using namespace boost::system;
	using namespace net;
	using namespace async;

	class Session;
	typedef boost::shared_ptr<Session> SessionPtr;

	class Session
		: public ChannelHub<ISession>
	{
		TClientSid _sid;
	public:
		Session(const TClientSid sid);
		~Session();

		virtual Result2<error_code, size_t> watchState();
		virtual void balance(size_t numChannels);
		virtual TClientSid sid();
		virtual IAgentPtr allocAgent();
		virtual void close();

	};
}
#endif
