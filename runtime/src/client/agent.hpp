#ifndef _CLIENT_AGENT_HPP_
#define _CLIENT_AGENT_HPP_

#include "client/iagent.hpp"
#include "client/endpoint.hpp"

namespace client
{
	using namespace boost;
	using namespace boost::system;
	using namespace async;

	class Session;
	typedef boost::shared_ptr<Session> SessionPtr;

	//////////////////////////////////////////////////////////////////////////
	class Agent
		: public IAgent
		, public enable_shared_from_this<Agent>
	{
		SessionPtr	_session;
		TEndpoint	_endpoint;

		boost::function<void(server::TEndpoint, utils::VariantPtr)> _onReceive;

		mutex		_mtx;
		bool		_closed;
	public:
		void onReceive(const server::TEndpoint &endpoint, utils::VariantPtr data);
		void close();

	public:
		Agent(SessionPtr session, TEndpoint	endpoint);
		~Agent();

		virtual Result<error_code> send(
			const server::TEndpoint &endpoint,
			utils::VariantPtr data);

		void listen(const boost::function<void(server::TEndpoint, utils::VariantPtr)> onReceive);

		virtual ISessionPtr getSession();
	};
	typedef shared_ptr<Agent> AgentPtr;
}
#endif
