// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "pgs/meta/cluster.hpp"

#include "pgs/meta/schemas/TestCategories.hpp"
#include "pgs/meta/schemas/Mixed.hpp"
#include "pgs/meta/schemas/ForFields.hpp"

#include "pgs/meta/schemas/TestCategories_initializer.hpp"
#include "pgs/meta/schemas/Mixed_initializer.hpp"
#include "pgs/meta/schemas/ForFields_initializer.hpp"


#include "pgc/connection.hpp"

#include "pgs/cluster.hpp"
#include "pgs/select.hpp"
#include "pgs/expressionSugar.hpp"

#include "pgs/field.hpp"
#include "pgs/category.hpp"
#include "pgs/link.hpp"

//////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	pgs::meta::Cluster mcl;

	mcl.add<pgs::meta::schemas::TestCategories>();
	mcl.add<pgs::meta::schemas::Mixed>();
	mcl.add<pgs::meta::schemas::ForFields>();
	mcl.initialize();

	{
		pgs::meta::SchemaCPtr s = mcl.getByName("TestCategories");
		s->_categories["Document"]->_name;
		s->_categories["Contract"]->_fields["file"]->_name;
	}

	{
		pgs::meta::schemas::TestCategoriesCPtr s = mcl.get<pgs::meta::schemas::TestCategories>();
		s->Contract->file->_name;

// 		BOOST_FOREACH(pgs::meta::CategoryPtr cat, s->_categories)
// 		{
// 			cat->_name = "sdfg";
// 		}
		int k=220;
	}





	//////////////////////////////////////////////////////////////////////////
	pgc::Connection con;
	//con.log(std::cout, pgc::lf_all);
	con.open("dbname=test user=postgres password=postgres port=5432");

	pgs::Cluster ccl(mcl);
	ccl.setUnicators("pref", "suff");
	ccl.con(con);

	//con.once("BEGIN").exec();

	pgs::TSyncLog log;
	bool bc = ccl.sync(log, true);
	bool bd = true;//ccl->drop(log);

	std::cout<<bc<<", "<<bd<<std::endl;

	BOOST_FOREACH(const pgs::SyncLogLine &l, log)
	{
		std::cout<<l._msg<<", "<<l._data1<<", "<<l._data2<<", "<<l._data3<<std::endl;
	}




	pgs::meta::schemas::TestCategoriesCPtr testCats = mcl.get<pgs::meta::schemas::TestCategories>();
	pgs::Select mysel;

	mysel
		.from(pgs::Category(testCats->Client, "clientAlias"))
		.links(pgs::Link("clientAlias", testCats->Client->observableServices, "observableServicesAlias"))
		.links(pgs::Link("clientAlias", testCats->Client->services, "servicesAlias"))

		.whats(pgs::Category(testCats->Client, "clientAlias"))
		.whats(pgs::Field("clientAlias", testCats->Client->name))
		//.whats(pgs::Field(testCats->Client->name))

		.where(
			pgs::Field("observableServicesAlias", testCats->Service->description) > pgs::Value("v1") && 
			pgs::Field("servicesAlias", testCats->ServicePart->id) <= pgs::Value("v2")
		)
		.limit(pgs::Value("v3"))
		.offset(pgs::Value("v4"));
		
	//testCats->

	//mysel.exec(con);

	pgs::Statement stmt = mysel.compile(ccl);

// 	stmt.bind(std::string("dgh"), "v1");
// 	stmt.bind(20, "v2");
// 	stmt.bind(20, "v3");
// 	stmt.bind(20, "v4");
	stmt.bind(std::string("dgh"));
	stmt.bind(20);
	stmt.bind(20);
	stmt.bind(20);

	pgs::Result r = stmt.exec();

	std::cout<<r.rows()<<std::endl;

	return 0;
}

