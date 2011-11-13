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
	typedef std::vector<std::string> TV;
	TV v;
	std::cout<<sizeof(TV)<<endl;
	std::cout<<sizeof(std::_Vector_val<std::string, TV::allocator_type>)<<endl;
	return 0;

// 
// 	//////////////////////////////////////////////////////////////////////////
// 	pgs::meta::Cluster mcl;
// 
// 	mcl.add<pgs::meta::schemas::TestCategories>();
// 	mcl.add<pgs::meta::schemas::Mixed>();
// 	mcl.add<pgs::meta::schemas::ForFields>();
// 	mcl.initialize();
// 
// 	{
// 		pgs::meta::SchemaCPtr s = mcl.getByName("TestCategories");
// 		s->_categories["Document"]->_name;
// 		s->_categories["Contract"]->_fields["file"]->_name;
// 	}
// 
// 	{
// 		pgs::meta::schemas::TestCategoriesCPtr s = mcl.get<pgs::meta::schemas::TestCategories>();
// 		s->Contract->file->_name;
// 
// // 		BOOST_FOREACH(pgs::meta::CategoryPtr cat, s->_categories)
// // 		{
// // 			cat->_name = "sdfg";
// // 		}
// 		int k=220;
// 	}
// 
// 
// 
// 
// 
// 	//////////////////////////////////////////////////////////////////////////
// 	pgc::Connection con;
// 	con.log(std::cout, pgc::lf_all);
// 	con.open("dbname=test user=postgres password=postgres port=5432");
// 
// 	pgs::Cluster ccl(mcl);
// 	ccl.setUnicators("pref", "suff");
// 	ccl.con(con);
// 
// 	//con.once("BEGIN").exec();
// 
// 	pgs::TSyncLog log;
// 	bool bc = true;//ccl.sync(log, true);
// 	bool bd = true;//ccl->drop(log);
// 
// 	std::cout<<bc<<", "<<bd<<std::endl;
// 
// 	BOOST_FOREACH(const pgs::SyncLogLine &l, log)
// 	{
// 		std::cout<<l._msg<<", "<<l._data1<<", "<<l._data2<<", "<<l._data3<<std::endl;
// 	}
// 
// 
// 
// 
// 	pgs::meta::schemas::TestCategoriesCPtr testCats = mcl.get<pgs::meta::schemas::TestCategories>();
// 	pgs::Select mysel;
// 
// 	mysel
// 		.from(pgs::Category(testCats->Client, "clientAlias"))
// 		.links(pgs::Link("clientAlias", testCats->Client->observableServices, "observableServicesAlias"))
// 		.links(pgs::Link("clientAlias", testCats->Client->services, "servicesAlias"))
// 
// 		.whats(pgs::Category(testCats->Client, "clientAlias"))
// 		//.whats(pgs::Field("clientAlias", testCats->Client->name))
// 		.whats(pgs::Category(testCats->Service, "servicesAlias"))
// 
// 		.where(
// 			pgs::Field("observableServicesAlias", testCats->Service->description) > pgs::Value("v1") && 
// 			pgs::Field("servicesAlias", testCats->ServicePart->id) <= pgs::Value("v2")
// 		)
// 		.limit(pgs::Value("v3"))
// 		.offset(pgs::Value("v4"));
// 		
// 	//testCats->
// 
// 	//mysel.exec(con);
// 
// 	pgs::Statement stmt = mysel.compile(ccl);
// 
// // 	stmt.bind(std::string("dgh"), "v1");
// // 	stmt.bind(20, "v2");
// // 	stmt.bind(20, "v3");
// // 	stmt.bind(20, "v4");
// 	stmt.bind(std::string("a"));
// 	stmt.bind(20, "v2");
// 	stmt.bind(20, "v3");
// 	stmt.bind(1, "v4");
// 
// 	pgs::Result r = stmt.exec();
// 
// 	std::cout<<r.rows()<<std::endl;
// 
// // 	std::cout<<r.fetchString(0)<<std::endl;
// // 	std::cout<<r.fetchString(0,1)<<std::endl;
// // 	std::cout<<r.fetchString(0,2)<<std::endl;
// // 	std::cout<<r.fetchString(0,3)<<std::endl;
// // 	std::cout<<r.fetchString(0,4)<<std::endl;
// // 	std::cout<<r.fetchString(0,5)<<std::endl;
// // 	std::cout<<r.fetchString(0,6)<<std::endl;
// // 	std::cout<<r.fetchString(0,7)<<std::endl;
// // 	std::cout<<r.fetchString(0,8)<<std::endl;
// 
// 	std::cout<<r.fetchString(0)<<std::endl;
// 	std::cout<<r.fetchString("id")<<std::endl;
// 	std::cout<<r.fetchString("sex")<<std::endl;
// 	std::cout<<r.fetchString("birth")<<std::endl;
// 	std::cout<<r.fetchString("photo")<<std::endl;
// 	std::cout<<r.fetchString("name")<<std::endl;
// 	std::cout<<r.fetchString("middlename")<<std::endl;
// 	std::cout<<r.fetchString("surname")<<std::endl;
// 	std::cout<<r.fetchString("name")<<std::endl;

	return 0;
}

