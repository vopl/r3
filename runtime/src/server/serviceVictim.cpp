#include "pch.h"
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
	void ServiceVictim::onResult(pgc::IResultPtr r)
	{
		cnt++;
		if(!(cnt%100000))
		{
			pgc::EResultStatus s = r->status();
			const char *msg = r->errorMsg();
			utils::Variant v;
			r->fetchRowsMap(v);
			std::cout<<__FUNCTION__<<": "<<cnt<<", "<<s<<", "<<msg<<", "<<v<<std::endl;
		}
	}

	pgc::IStatementPtr s;

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onConnection(pgc::IConnectionPtr c)
	{
		if(!c)
		{
			std::cout<<"onConnection NULL"<<std::endl;
			return;
		}
		if(!s || (rand()%50)==25)
		{
			s = _pluma->create<pgc::IStatementProvider>();
			s->setSql("SELECT * FROM t_club");
		}

		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));

// 		boost::xtime xt;
// 		boost::xtime_get(&xt, boost::TIME_UTC);
// 		xt.sec += 1;
// 		boost::thread::sleep(xt);

		if(!_db)
		{
			return;
		}
		_db->allocConnection(
			bind(&ServiceVictim::onConnection, shared_from_this(), _1));
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onConnection2(pgc::IConnectionPtr c)
	{
		if(!c)
		{
			std::cout<<"onConnection2 NULL"<<std::endl;
			return;
		}

		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));
		c->exec(s, //v,
			bind(&ServiceVictim::onResult, shared_from_this(), _1));

// 		boost::xtime xt;
// 		boost::xtime_get(&xt, boost::TIME_UTC);
// 		xt.sec += 1;
// 		boost::thread::sleep(xt);

		if(!_db)
		{
			return;
		}
		_db->allocConnection(
			bind(&ServiceVictim::onConnection2, shared_from_this(), _1));
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
		_pluma = hub->getServer()->getPlugs();
		_db = hub->getServer()->getDb();

		_db->allocConnection(
			bind(&ServiceVictim::onConnection, shared_from_this(), _1));
		_db->allocConnection(
			bind(&ServiceVictim::onConnection2, shared_from_this(), _1));

		int k = 220;
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onHubDel(IServiceHubPtr hub)
	{
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
