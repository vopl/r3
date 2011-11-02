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

//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	boost::shared_ptr<pgs::meta::Cluster> mcl(new pgs::meta::Cluster);

	mcl->add<pgs::meta::schemas::TestCategories>();
	mcl->add<pgs::meta::schemas::Mixed>();
	mcl->add<pgs::meta::schemas::ForFields>();
	mcl->initialize();

	{
		pgs::meta::SchemaCPtr s = mcl->getByName("TestCategories");
		s->_categories["Document"]->_name;
		s->_categories["Contract"]->_fields["file"]->_name;
	}

	{
		pgs::meta::schemas::TestCategoriesCPtr s = mcl->get<pgs::meta::schemas::TestCategories>();
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

	boost::shared_ptr<pgs::Cluster> ccl(new pgs::Cluster(mcl));
	ccl->setUnicators("pref", "suff");
	ccl->setConnection(con);

	//con.once("BEGIN").exec();

	pgs::TSyncLog log;
	bool bc = true;//ccl->sync(log, true);
	bool bd = true;//ccl->drop(log);

	std::cout<<bc<<", "<<bd<<std::endl;

	BOOST_FOREACH(const pgs::SyncLogLine &l, log)
	{
		std::cout<<l._msg<<", "<<l._data1<<", "<<l._data2<<", "<<l._data3<<std::endl;
	}




// 	//////////////////////////////////////////////////////////////////////////
// 	pgs::Cluster wcl(ccl);
// 
// 	pgs::meta::schemas::TestCategoriesCPtr testCats = mcl->get<pgs::meta::schemas::TestCategories>();
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

	pgs::meta::schemas::TestCategoriesCPtr testCats = mcl->get<pgs::meta::schemas::TestCategories>();
	pgs::Select mysel;

	mysel
		.what(testCats->Client)
		.what(testCats->Letter->file)
		.link(testCats->Letter->servicePart)
		.where(pgs::Field(testCats->Letter->creation) && pgs::Field(testCats->Letter->creation))
		.limit(20);

	//mysel.exec(con);

	return 0;
}

