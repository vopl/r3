#ifndef _CLIENT_IAGENT_HPP_
#define _CLIENT_IAGENT_HPP_

#include "utils/variant.hpp"
#include "server/endpoint.hpp"

namespace client
{
	//////////////////////////////////////////////////////////////////////////
	struct IAgentHub;
	typedef boost::shared_ptr<IAgentHub> IAgentHubPtr;

	//////////////////////////////////////////////////////////////////////////
	struct IAgent
	{
		virtual ~IAgent(){}

		virtual void onReceive(
			IAgentHubPtr hub,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data) =0;
	};
	typedef boost::shared_ptr<IAgent> IAgentPtr;
}
#endif
