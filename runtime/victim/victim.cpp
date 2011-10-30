// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "dbMeta/cluster.hpp"

#include "dbMeta/schemas/TestCategories.hpp"
#include "dbMeta/schemas/Mixed.hpp"
#include "dbMeta/schemas/ForFields.hpp"

#include "dbMeta/schemas/TestCategories_initializer.hpp"
#include "dbMeta/schemas/Mixed_initializer.hpp"
#include "dbMeta/schemas/ForFields_initializer.hpp"


#include "pgc/connection.hpp"

#include "dbCreator/cluster.hpp"
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	boost::shared_ptr<dbMeta::Cluster> mcl(new dbMeta::Cluster);

	mcl->add<dbMeta::schemas::TestCategories>();
	mcl->add<dbMeta::schemas::Mixed>();
	mcl->add<dbMeta::schemas::ForFields>();
	mcl->initialize();

	{
		dbMeta::SchemaCPtr s = mcl->getByName("TestCategories");
		s->_categories["Document"]->_name;
		s->_categories["Contract"]->_fields["file"]->_name;
	}

	{
		dbMeta::schemas::TestCategoriesCPtr s = mcl->get<dbMeta::schemas::TestCategories>();
		s->Contract->file->_name;

// 		BOOST_FOREACH(dbMeta::CategoryPtr cat, s->_categories)
// 		{
// 			cat->_name = "sdfg";
// 		}
		int k=220;
	}





	//////////////////////////////////////////////////////////////////////////
	pgc::Connection con;
	con.open("dbname=test user=postgres password=postgres port=5432");

	boost::shared_ptr<dbCreator::Cluster> ccl(new dbCreator::Cluster(mcl));
	ccl->setUnicators("pref", "suff");
	ccl->setConnection(con);

	dbCreator::TSyncLog log;
	bool b = ccl->sync(log, true);

	std::cout<<b<<std::endl;

	BOOST_FOREACH(const dbCreator::SyncLogLine &l, log)
	{
		std::cout<<l._msg<<", "<<l._data1<<", "<<l._data2<<", "<<l._data3<<std::endl;
	}
	return 0;
}

