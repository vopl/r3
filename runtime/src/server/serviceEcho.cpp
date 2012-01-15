#include "pch.h"
#include "serviceEcho.hpp"
#include "server/inodeManager.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	ServiceEcho::ServiceEcho()
		: Base("echo")
	{
	}


	//////////////////////////////////////////////////////////////////////////
	void ServiceEcho::call(
		INodeManagerPtr manager,
		ISessionPtr session,
		const client::TEndpoint &endpoint,
		utils::VariantPtr data)
	{
		Future<error_code> res = manager->send(shared_from_this(), session, endpoint, data);

// 		res.wait();
// 		assert(!res.data());
	}
}
