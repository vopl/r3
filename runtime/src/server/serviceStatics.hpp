#ifndef _SERVER_SERVICESTATICS_HPP_
#define _SERVER_SERVICESTATICS_HPP_

#include "server/nodeBase.hpp"
#include <boost/filesystem.hpp>

namespace server
{
	using namespace boost;

	//////////////////////////////////////////////////////////////////////////
	class ServiceStatics
		: public NodeBase<ServiceStatics, true, true>
	{
		typedef NodeBase<ServiceStatics, true, true> Base;

		boost::filesystem::path	_root;

	public:
		ServiceStatics();
		~ServiceStatics();

		virtual void call(
			INodeManagerPtr manager,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data);
	};
	typedef boost::shared_ptr<ServiceStatics> ServiceStaticsPtr;

	//////////////////////////////////////////////////////////////////////////
	PLUMA_INHERIT_PROVIDER(ServiceStatics, INode);
}
#endif
