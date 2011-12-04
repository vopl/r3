#ifndef _CLIENT_AGENTHUB_HPP_
#define _CLIENT_AGENTHUB_HPP_

#include "pluma/pluma.hpp"
#include "client/iagentHub.hpp"
#include "client/endpoint.hpp"
#include <boost/enable_shared_from_this.hpp>
#include <boost/uuid/random_generator.hpp>

namespace client
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	struct AgentHub
		: public IAgentHub
		, public enable_shared_from_this<AgentHub>
	{
		ISessionPtr	_session;
		typedef std::map<TEndpoint, IAgentPtr> TMAgentsFwd;
		typedef std::map<IAgentPtr, TEndpoint> TMAgentsBwd;

		TMAgentsFwd	_agentsFwd;
		TMAgentsBwd	_agentsBwd;

		boost::uuids::random_generator _endpointGenerator;
		mutex	_mtx;

	private:
		void onReceiveOk(const net::SPacket &p);
		void onReceiveFail(system::error_code ec);

		void onSendOk();
		void onSendFail(system::error_code ec);

	public:
		AgentHub();
		virtual ~AgentHub();

		virtual void initialize(ISessionPtr session);
		virtual void deinitialize();

		virtual void addAgent(IAgentPtr agent);
		virtual void delAgent(IAgentPtr agent);

		virtual void send(
			IAgentPtr agent,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data);
	};
	typedef boost::shared_ptr<AgentHub> AgentHubPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_INHERIT_PROVIDER(AgentHub, IAgentHub);
}
#endif
