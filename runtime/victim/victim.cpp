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
#include "utils/variant.hpp"


//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	utils::Variant v;

	v = std::string("220");
	v = 1.234f;
	v = 1.234;

	v = boost::int8_t(23);
	v = boost::int16_t(24);
	v = boost::int32_t(25);
	v = boost::int64_t(26);
	v = boost::uint8_t(27);
	v = boost::uint16_t(28);
	v = boost::uint32_t(29);
	v = boost::uint64_t(30);

	utils::Variant::VectorChar vc;
	vc.push_back(10);
	vc.push_back(20);
	v = vc;

	utils::Variant::Date d(2003, 1,2);
	v = d;

	utils::Variant::Time t(d, utils::Variant::TimeDuration(1,2,3));
	v = t;

	utils::Variant::VectorVariant vv;
	vv.push_back(v);
	vv.push_back(utils::Variant(10));
	v = vv;

	utils::Variant::MapStringVariant msv;
	msv["one"] = v;
	msv["two"] = vc;
	msv["three"] = t;
	msv["four"] = vv;
	v = msv;


	v = true;

	std::tm tm = {};
	tm.tm_year = 111;
	tm.tm_mon = 3;
	tm.tm_mday = 4;
	tm.tm_hour = 5;
	tm.tm_min = 6;
	tm.tm_sec = 7;
	tm.tm_isdst = 1;
	v = tm;


	utils::Variant::Bitset8 bs8(std::string("010111"));
	v = bs8;
	utils::Variant::Bitset16 bs16(std::string("010111"));
	v = bs16;
	utils::Variant::Bitset32 bs32(std::string("010111"));
	v = bs32;
	utils::Variant::Bitset64 bs64(std::string("010111"));
	v = bs64;
	utils::Variant::Bitset128 bs128(std::string("010111"));
	v = bs128;
	utils::Variant::Bitset256 bs256(std::string("010111"));
	v = bs256;
	utils::Variant::Bitset512 bs512(std::string("010111"));
	v = bs512;

	utils::Variant::DateDuration dd(23);
	v = dd;

	utils::Variant::TimeDuration td(23,14,32);
	v = td;

	utils::Variant::DateTimeDuration dtd(dd, td);
	v = dtd;

	utils::Variant::MapVariantVariant mvv;
	mvv["v"]="v";
	mvv[dd]=mvv;
	v = mvv;

	utils::Variant::MultimapVariantVariant mmvv;
	mmvv.insert(std::make_pair("v", "v"));
	mmvv.insert(std::make_pair(dd, mmvv));
	v = mmvv;

	utils::Variant::MultimapStringVariant mmsv;
	mmsv.insert(std::make_pair("v", "v"));
	mmsv.insert(std::make_pair("dd", mmvv));
	v = mmsv;

	utils::Variant::SetVariant sv;
	sv.insert("v");
	sv.insert("mmsv");
	v = sv;

	utils::Variant::MultisetVariant msetv;
	msetv.insert("v");
	msetv.insert("v");
	msetv.insert("msetv");
	v = msetv;

	utils::Variant::DequeVariant dv;
	dv.push_back("v");
	dv.push_back(dd);
	v = dv;

	utils::Variant::ListVariant lv;
	lv.push_back("v");
	lv.push_back(dd);
	v = lv;

	std::cout<<sizeof(utils::Variant)<<endl;

	utils::Variant v2;
	v2.swap(v);
	v2.swap(v2);

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

