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
	ccl.setConnection(con);

	//con.once("BEGIN").exec();

	pgs::TSyncLog log;
	bool bc = ccl.sync(log, true);
	bool bd = true;//ccl->drop(log);

	std::cout<<bc<<", "<<bd<<std::endl;

	BOOST_FOREACH(const pgs::SyncLogLine &l, log)
	{
		std::cout<<l._msg<<", "<<l._data1<<", "<<l._data2<<", "<<l._data3<<std::endl;
	}




// 	//////////////////////////////////////////////////////////////////////////
// 	pgs::Cluster wcl(ccl);
// 
// 	pgs::meta::schemas::TestCategoriesCPtr testCats = mcl.get<pgs::meta::schemas::TestCategories>();
// 
// 	pgs::meta::Tuple<pgs::meta::schemas::TestCategories> lt;
// 	lt = wcl.select(testCats->Letter).where(testCats->Letter->comment < 220);
// 
// 	lt.comment = "380";
// 	wcl.update(lt, lt.comment);
// 	wcl.insert(lt);
// 	wcl.delete(lt);
// 
// 	pgs::meta::categories::TestCategories_LetterCPtr letter = testCats->Letter;
// 
// 	lt = wcl
// 		.select(letter)
// 		.distinct(letter->servisePart->cost)
// 		.link(letter->servisePart)
// 		
// 		.where(letter->lastModified < 220 &&
// 			letter->servisePart->cost < 380)
// 		.limit(10)
// 		.offset(3)
// 		.order(letter->servisePart->cost, letter->lastModified);
// 
// 	lt.servisePart[0].cost;

	pgs::meta::schemas::TestCategoriesCPtr testCats = mcl.get<pgs::meta::schemas::TestCategories>();
	pgs::Select mysel;

	mysel
		.whats(pgs::Category(testCats->Client))
		.whats(pgs::Field(testCats->Letter->file))
		.from(pgs::Category(testCats->Client, "clientAlias"))
		.links(pgs::Link("clientAlias", testCats->Client->observableServices, "observableServicesAlias"))
		.links(pgs::Link(testCats->Client->services, "servicesAlias"))
		.where(pgs::Field(testCats->Letter->creation) && pgs::Field(testCats->Letter->creation))
		.limit(pgs::Value(20));
		
	//testCats->

	//mysel.exec(con);

	std::string sql;
	mysel.compile(sql, ccl);

	return 0;
}

