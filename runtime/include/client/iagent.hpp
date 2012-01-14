#ifndef _CLIENT_IAGENT_HPP_
#define _CLIENT_IAGENT_HPP_

#include "utils/variant.hpp"
#include "server/endpoint.hpp"
#include "async/future.hpp"
#include <boost/system/error_code.hpp>
#include <boost/function.hpp>

namespace client
{
	//////////////////////////////////////////////////////////////////////////
	struct ISession;
	typedef boost::shared_ptr<ISession> ISessionPtr;

	//////////////////////////////////////////////////////////////////////////
	struct IAgent
	{
		virtual ~IAgent(){}

		virtual async::Future<boost::system::error_code> send(
			const server::TEndpoint &endpoint,
			utils::VariantPtr data) =0;

		virtual void listen(const boost::function<void(server::TEndpoint, utils::VariantPtr)> onReceive) =0;

		virtual ISessionPtr getSession() =0;
	};
	typedef boost::shared_ptr<IAgent> IAgentPtr;
}
#endif
