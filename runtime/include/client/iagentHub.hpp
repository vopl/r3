#ifndef _CLIENT_IAGENTHUB_HPP_
#define _CLIENT_IAGENTHUB_HPP_

#include "pluma/pluma.hpp"
#include "client/iagent.hpp"
#include "client/isession.hpp"

namespace client
{
	struct IAgentHub
	{
		virtual ~IAgentHub(){}
		virtual void initialize(ISessionPtr session) =0;
		virtual void deinitialize() =0;

		virtual void addAgent(IAgentPtr agent) =0;
		virtual void delAgent(IAgentPtr agent) =0;

		virtual void send(
			IAgentPtr agent,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data) =0;

	};
	typedef boost::shared_ptr<IAgentHub> IAgentHubPtr;

	PLUMA_PROVIDER_HEADER(IAgentHub, 1, 1);
}
#endif
