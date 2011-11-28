#include "pch.h"
#include "serviceEcho.hpp"
#include "server/iserviceHub.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	void ServiceEcho::onSendOk()
	{
		//
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ServiceEcho::onSendFail(system::error_code ec)
	{
		//
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
		TEndpoint endpoint,
		utils::VariantPtr data)
	{
		hub->send(shared_from_this(), session, endpoint, data, 
			bind(&ServiceEcho::onSendOk, shared_from_this()),
			bind(&ServiceEcho::onSendFail, shared_from_this(), _1));
	}
}
