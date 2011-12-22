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
		if(!(cnt%1000))
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
			if(!_db)
			{
				TLOG("connectionLoop1 db NULL");
				return;
			}
			async::Result<pgc::IConnectionPtr> c1=_db->allocConnection();
			async::Result<pgc::IConnectionPtr> c2=_db->allocConnection();
			async::Result<pgc::IConnectionPtr> c3=_db->allocConnection();
			async::Result<pgc::IConnectionPtr> c4=_db->allocConnection();

			//TLOG("connectionLoop1");
			if(!s)// || !(rand()%2))
			{
				s = _pluma->create<pgc::IStatementProvider>();
				s->setSql("SELECT pg_sleep($1)");
			}

			if(!c1.data() || !c2.data() || !c3.data() || !c4.data())
			{
				TLOG("connectionLoop1 c NULL");
				return;
			}

			std::vector<async::Result<pgc::IResultPtrs> > vresults;
			for(size_t i(0); i<10; i++)
			{
				vresults.push_back(c1.data()->query(s, utils::Variant(double(rand())/RAND_MAX/10)));
				vresults.push_back(c2.data()->query(s, utils::Variant(double(rand())/RAND_MAX/10)));
				vresults.push_back(c3.data()->query(s, utils::Variant(double(rand())/RAND_MAX/10)));
				vresults.push_back(c4.data()->query(s, utils::Variant(double(rand())/RAND_MAX/10)));
			}
			std::random_shuffle(vresults.begin(), vresults.end());

			async::ResultWaiter<pgc::IResultPtrs> results;
			BOOST_FOREACH(async::Result<pgc::IResultPtrs> r, vresults)
			{
				results |= r;

			}


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

		for(size_t i(0); i<20; i++)
		{
			async::spawn(bind(&ServiceVictim::connectionLoop1, shared_from_this()));
		}

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
