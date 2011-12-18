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
		TLOG("onResult");

		cnt++;
		if(!(cnt%100000))
		{
			pgc::EResultStatus s = r[0]->status();
			const char *msg = r[0]->errorMsg();
			utils::Variant v;
			r[0]->fetchRowsMap(v);
			TLOG(cnt<<", "<<s<<", "<<msg<<", "<<v);
		}
	}

	pgc::IStatementPtr s;

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onConnection(pgc::IConnectionPtr c)
	{
		for(;;)
		{
			if(!c)
			{
				TLOG("onConnection NULL");
				return;
			}
			TLOG("onConnection");
			if(!s || (rand()%50)==25)
			{
				s = _pluma->create<pgc::IStatementProvider>();
				s->setSql("SELECT '123.456789'::numeric");
			}

			c->query(s, //v,
				bind(&ServiceVictim::onResult, shared_from_this(), _1));
			c.reset();

			if(!_db)
			{
				return;
			}
			async::Result<pgc::IConnectionPtr> cr = _db->allocConnection();
			cr.wait();
			c = cr.data();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onConnection2(pgc::IConnectionPtr c)
	{
		if(!c)
		{
			TLOG("onConnection2 NULL");
			return;
		}
		TLOG("onConnection2");
		if(!s || (rand()%50)==25)
		{
			s = _pluma->create<pgc::IStatementProvider>();
			s->setSql("SELECT '123.456789'::numeric");
		}

// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));
// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));
// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));
// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));
// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));
// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));
// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));
// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));
// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));
// 		c->query(s, //v,
// 			bind(&ServiceVictim::onResult, shared_from_this(), _1));

// 		boost::xtime xt;
// 		boost::xtime_get(&xt, boost::TIME_UTC);
// 		xt.sec += 1;
// 		boost::thread::sleep(xt);

		if(!_db)
		{
			return;
		}
		async::Result<pgc::IConnectionPtr> cr = _db->allocConnection();
		cr.wait();
		onConnection2(cr.data());
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

		async::Result<pgc::IConnectionPtr> cr = _db->allocConnection();

// 		async::Result<pgc::IConnectionPtr> cr2 = _db->allocConnection();

		cr.wait();
		onConnection(cr.data());
// 		cr2.wait();
// 		onConnection2(cr.data());

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
