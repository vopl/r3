#include "pch.h"
#include "serviceEcho.hpp"
#include "server/iserviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	const TEndpoint ServiceEcho::_endpoint = "echo";

	//////////////////////////////////////////////////////////////////////////
	const TEndpoint &ServiceEcho::getEndpoint()
	{
		return _endpoint;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceEcho::onHubAdd(IServiceHubPtr hub)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceEcho::onHubDel(IServiceHubPtr hub)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceEcho::onSessionAdd(ISessionPtr session)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceEcho::onSessionDel(ISessionPtr session)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceEcho::onReceive(
		IServiceHubPtr hub,
		ISessionPtr session,
		const client::TEndpoint &endpoint,
		utils::VariantPtr data)
	{
		Future<error_code> res = hub->send(shared_from_this(), session, endpoint, data);

// 		res.wait();
// 		assert(!res.data());
	}
}
