#ifndef _CLIENT_IAGENTHUB_HPP_
#define _CLIENT_IAGENTHUB_HPP_

#include "client/iagent.hpp"
#include <boost/function.hpp>
#include <boost/system/error_code.hpp>

namespace client
{
	struct IAgentHub
	{
		virtual ~IAgentHub(){}

		virtual void addAgent(IAgentPtr agent) =0;
		virtual void delAgent(IAgentPtr agent) =0;

		virtual void send(
			IAgentPtr agent,
			const server::TEndpoint &endpoint,
			utils::VariantPtr data,
			boost::function<void ()> ok,
			boost::function<void (boost::system::error_code)> fail) =0;

	};
	typedef boost::shared_ptr<IAgentHub> IAgentHubPtr;
}
#endif
