#include "pch.h"

#undef LOG_NAME
#define LOG_NAME server_victim
#include "log/client.hpp"

#include "serviceVictim.hpp"
#include "server/iserviceHub.hpp"
#include "server/iserver.hpp"
#include "async/futureWaiter.hpp"

#include "pgs/cluster.hpp"
#include "pgs/meta/schemas/Staff_initializer.hpp"
#include "pgs/select.hpp"

#include "utils/ntoa.hpp"

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
	void ServiceVictim::onResult(pgc::Result r)
	{
		cnt++;
		if(!(cnt%10000))
		{
			pgc::EResultStatus s = r.status();
			const char *msg = r.errorMsg();
			utils::Variant v;
			r.fetchRowsMap(v);
			TLOG(cnt<<", "<<s<<", "<<msg<<", "<<v);
		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::connectionLoop1()
	{
		pgc::Statement s;
		for(;;)
		{
			if(!_db)
			{
				TLOG("connectionLoop1 db NULL");
				return;
			}
			async::Future<pgc::Connection> c1=_db.allocConnection();
			async::Future<pgc::Connection> c2=_db.allocConnection();
			async::Future<pgc::Connection> c3=_db.allocConnection();
			async::Future<pgc::Connection> c4=_db.allocConnection();

			//TLOG("connectionLoop1");
			if(!s || !(rand()%5))
			{
				s = pgc::Statement("SELECT $1");
			}

			if(!c1.data() || !c2.data() || !c3.data() || !c4.data())
			{
				TLOG("connectionLoop1 c NULL");
				return;
			}

			async::FutureWaiter<pgc::Result> results(
				c1.data().query(s, utils::Variant(double(rand())/RAND_MAX/10000))
				);
			//async::EventWaiter<async::Future<pgc::IResultPtrs> > results;

			for(size_t i(0); i<10; i++)
			{
				results << c1.data().query(s, utils::Variant(double(rand())/RAND_MAX/10000));
				results << c2.data().query(s, utils::Variant(double(rand())/RAND_MAX/10000));
				results << c3.data().query(s, utils::Variant(double(rand())/RAND_MAX/10000));
				results << c4.data().query(s, utils::Variant(double(rand())/RAND_MAX/10000));
			}


// 			while(results.wait())
// 			{
//  				onResult(results.current());
// 			}
			while(results)
			{
				onResult(results);
			}

		}
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::syncPgs()
	{
		pgs::meta::Cluster mcl;
		mcl.add<pgs::meta::schemas::Staff>();
		mcl.initialize();
		
		pgs::Cluster cl(mcl);

		static volatile size_t k(0);
		char tmp[64];
		cl.setUnicators(std::string("pre_")+utils::_ntoa(k++, tmp), "post");

		for(size_t i(0); i<50000; i++)
		{
			if(!_db)
			{
				return;
			}
			pgc::Connection con = _db.allocConnection();
			if(!con)
			{
				return;
			}

			con.query("BEGIN").wait();
			async::Future<bool> sar = cl.sync(con, true);
			async::Future<bool> dar = cl.drop(con);

			sar.wait();
			dar.wait();

// 			pgs::meta::schemas::StaffCPtr staff = mcl.get<pgs::meta::schemas::Staff>();
// 
// 			pgs::Statement s = pgs::Select()
// 				.whats(pgs::Category(staff->Right))
// 				.from(staff->Right)
// 				.links(staff->Right->values)
// 				.orders(staff->Right->module)
// 				.compile(cl);

			//con.query(s, sd);
			con.query("COMMIT").wait();
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

// 		for(size_t i(0); i<1; i++)
// 		{
// 			async::spawn(bind(&ServiceVictim::syncPgs, shared_from_this()));
// 		}

		int k = 220;
		//
	}

	//////////////////////////////////////////////////////////////////////////
	void ServiceVictim::onHubDel(IServiceHubPtr hub)
	{
		TLOG("del from hub");
		_db = pgc::Db();
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
		async::Future<boost::system::error_code> res =
		hub->send(shared_from_this(), session, endpoint, data);

		res.wait();
		if(res.data())
		{
			onSendFail(res.data());
		}
		else
		{
			onSendOk();
		}
	}
}
