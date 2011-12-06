#include "pch.h"
#include "serviceVictim.hpp"
#include "server/iserviceHub.hpp"
#include "server/iserver.hpp"
#include "pgc/idb.hpp"

namespace server
{
	//////////////////////////////////////////////////////////////////////////
	const TEndpoint ServiceVictim::_endpoint = "victim";

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onSendOk()
	{
		//
	}
	
	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onSendFail(system::error_code ec)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onResult(pgc::IResultPtr r)
	{
		std::cout<<r->errorCode()<<", "<<r->errorMsg()<<std::endl;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onConnection(pgc::IConnectionPtr c)
	{
		pgc::IStatementPtr s = _pluma->create<pgc::IStatementProvider>();
		s->setSql("show server_version");
		c->exec(s, 
			bind(&ServiceVictim::onResult, shared_from_this(), _1));

	}


	//////////////////////////////////////////////////////////////////////////
	const TEndpoint &ServiceVictim::getEndpoint()
	{
		return _endpoint;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onHubAdd(IServiceHubPtr hub)
	{
		_pluma = hub->getServer()->getPlugs();
		pgc::IDbPtr db = hub->getServer()->getDb();

		db->allocConnection(
			bind(&ServiceVictim::onConnection, shared_from_this(), _1));

		int k = 220;
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onHubDel(IServiceHubPtr hub)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onSessionAdd(ISessionPtr session)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onSessionDel(ISessionPtr session)
	{
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onReceive(
		IServiceHubPtr hub,
		ISessionPtr session,
		const client::TEndpoint &endpoint,
		utils::VariantPtr data)
	{
		hub->send(shared_from_this(), session, endpoint, data, 
			bind(&ServiceVictim::onSendOk, shared_from_this()),
			bind(&ServiceVictim::onSendFail, shared_from_this(), _1));
	}
}
