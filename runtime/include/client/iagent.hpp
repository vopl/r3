#ifndef _CLIENT_IAGENT_HPP_
#define _CLIENT_IAGENT_HPP_

#include "utils/variant.hpp"
#include "server/endpoint.hpp"
#include "async/result.hpp"
#include <boost/system/error_code.hpp>

namespace client
{
	//////////////////////////////////////////////////////////////////////////
	struct IAgentHub;
	typedef boost::shared_ptr<IAgentHub> IAgentHubPtr;

	//////////////////////////////////////////////////////////////////////////
	struct IAgent
	{
		virtual ~IAgent(){}

		virtual async::Result<boost::system::error_code> send(
			const server::TEndpoint &endpoint,
			utils::VariantPtr data) =0;

		virtual async::Result3<boost::system::error_code, server::TEndpoint, utils::VariantPtr> receive() =0;
	};
	typedef boost::shared_ptr<IAgent> IAgentPtr;
}
#endif
