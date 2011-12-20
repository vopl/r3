#include "pch.h"

#undef LOG_NAME
#define LOG_NAME server_victim
#include "log/client.hpp"

#include "serviceVictim.hpp"
#include "server/iserviceHub.hpp"
#include "server/iserver.hpp"

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
		for(;;)
		{
			async::Result<pgc::IConnectionPtr> cr = _db->allocConnection();
			cr.wait();
			pgc::IConnectionPtr c = cr.data();
			
			if(!c)
			{
				TLOG("connectionLoop1 NULL");
				return;
			}
			//TLOG("connectionLoop1");
			if(!s || !(rand()%2))
			{
				s = _pluma->create<pgc::IStatementProvider>();
				s->setSql("SELECT '123.456789'::numeric");
			}

 			async::Result<pgc::IResultPtrs> res = c->query(s);
 			async::Result<pgc::IResultPtrs> res2 = c->query(s);
			c.reset();

 			onResult(res.data());
 			onResult(res2.data());

			if(!_db)
			{
				return;
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

		hub->getServer()->getAsync()->post(bind(&ServiceVictim::connectionLoop1, shared_from_this()));
 		hub->getServer()->getAsync()->post(bind(&ServiceVictim::connectionLoop1, shared_from_this()));
 		hub->getServer()->getAsync()->post(bind(&ServiceVictim::connectionLoop1, shared_from_this()));
 		hub->getServer()->getAsync()->post(bind(&ServiceVictim::connectionLoop1, shared_from_this()));

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
