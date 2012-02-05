#ifndef _SERVER_ITASK_HPP_
#define _SERVER_ITASK_HPP_

#include "server/inodeManager.hpp"
#include "client/endpoint.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	struct ITask
	{
		virtual ~ITask(){}

		virtual void call(
			INodeManagerPtr hub,
			ISessionPtr session,
			const client::TEndpoint &endpoint,
			utils::VariantPtr data) =0;
	};
	typedef boost::shared_ptr<ITask> ITaskPtr;
}
#endif
