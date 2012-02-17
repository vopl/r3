#ifndef _SERVER_SERVICEECHO_HPP_
#define _SERVER_SERVICEECHO_HPP_

#include "server/nodeBase.hpp"

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class ServiceEcho
		: public NodeBase<ServiceEcho, true, true>
	{
		typedef NodeBase<ServiceEcho, true, true> Base;

	public:
		ServiceEcho();

		virtual void call(
			INodeManagerPtr manager,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data);
	};
	typedef boost::shared_ptr<ServiceEcho> ServiceEchoPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_INHERIT_PROVIDER(ServiceEcho, INode)
}
#endif
