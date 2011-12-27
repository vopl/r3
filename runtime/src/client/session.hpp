#ifndef _CLIENT_SESSION_HPP_
#define _CLIENT_SESSION_HPP_

#include "client/isession.hpp"
#include "net/channelHub.hpp"
#include "net/iconnector.hpp"
#include "client/endpoint.hpp"
#include "agent.hpp"

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
		typedef ChannelHub<ISession> Base;
		TClientSid _sid;

		typedef std::map<TEndpoint, Agent *> TMAgents;

		TMAgents	_agents;

		boost::uuids::random_generator _endpointGenerator;
		mutex	_mtx;
		bool	_closed;

	private:
		SessionPtr shared_from_this();

	private:
		void receiveLoop_f();

	public:
		Session(const TClientSid sid);
		~Session();

		virtual Result2<error_code, size_t> watchState();
		virtual void balance(size_t numChannels);
		virtual TClientSid sid();
		virtual IAgentPtr allocAgent();
		virtual void close();

	public:
		bool attachChannel(IChannelPtr channel);

		void freeAgent(const TEndpoint &endpoint);

	};
}
#endif
