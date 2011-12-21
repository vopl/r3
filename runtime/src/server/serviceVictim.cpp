#include "pch.h"

#undef LOG_NAME
#define LOG_NAME server_victim
#include "log/client.hpp"

#include "serviceVictim.hpp"
#include "server/iserviceHub.hpp"
#include "server/iserver.hpp"
#include "async/resultContainer.hpp"

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
	static size_t cnt(0);
	void ServiceVictim::onResult(pgc::IResultPtrs r)
	{
		assert(r.size()<2);
		if(r.empty())
		{
			TLOG("onResult NULL");
			return;
		}
		//TLOG("onResult");

		cnt++;
		if(!(cnt%10000))
		{
			pgc::EResultStatus s = r[0]->status();
			const char *msg = r[0]->errorMsg();
			utils::Variant v;
			r[0]->fetchRowsMap(v);
			TLOG(cnt<<", "<<s<<", "<<msg<<", "<<v);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::connectionLoop1()
	{
		pgc::IStatementPtr s;
		async::Result<pgc::IConnectionPtr> c=_db->allocConnection();
		for(;;)
		{
			//TLOG("connectionLoop1");
			if(!s)// || !(rand()%2))
			{
				s = _pluma->create<pgc::IStatementProvider>();
				s->setSql("SELECT '123.456789'::numeric");
			}

			if(!c.data())
			{
				TLOG("connectionLoop1 c NULL");
				return;
			}

			async::ResultWaiter<pgc::IResultPtrs> results;
			for(size_t i(0); i<20; i++)
			{
				results |= c.data()->query(s);
			}

			if(!_db)
			{
				TLOG("connectionLoop1 db NULL");
				return;
			}
			c = _db->allocConnection();

			while(results.wait())
			{
 				onResult(results.current());
			}

		}
	}

	//////////////////////////////////////////////////////////////////////////
	ServiceVictim::ServiceVictim()
	{

	}

	//////////////////////////////////////////////////////////////////////////
	ServiceVictim::~ServiceVictim()
	{

	}


	//////////////////////////////////////////////////////////////////////////
	const TEndpoint &ServiceVictim::getEndpoint()
	{
		return _endpoint;
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onHubAdd(IServiceHubPtr hub)
	{
		TLOG("add to hub");
		_pluma = hub->getServer()->getPlugs();
		_db = hub->getServer()->getDb();

		for(size_t i(0); i<1; i++)
		{
			async::spawn(bind(&ServiceVictim::connectionLoop1, shared_from_this()));
		}
//  		async::spawn(bind(&ServiceVictim::connectionLoop1, shared_from_this()));
//  		async::spawn(bind(&ServiceVictim::connectionLoop1, shared_from_this()));
//  		async::spawn(bind(&ServiceVictim::connectionLoop1, shared_from_this()));

		int k = 220;
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onHubDel(IServiceHubPtr hub)
	{
		TLOG("del from hub");
		_db.reset();
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
