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


#include "schemaSyncronizer.hpp"

#include "pgc/connection.hpp"
//////////////////////////////////////////////////////////////////////////

class Cluster
{
public:
	Cluster(dbMeta::Cluster *cluster, const std::string &prefix, const std::string &suffix);

// 	bool structureSync(log &log);
// 	bool structureDrop(log &log);

// 	select
// 	insert
// 	update
// 	delete
};

//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	dbMeta::Cluster cl;

	cl.add<dbMeta::schemas::TestCategories>();
	cl.add<dbMeta::schemas::Mixed>();
	cl.add<dbMeta::schemas::ForFields>();
	cl.initialize();

	{
		dbMeta::SchemaCPtr s = cl.getByName("TestCategories");
		s->_categories["Document"]->_name;
		s->_categories["Contract"]->_fields["file"]->_name;
	}

	{
		dbMeta::schemas::TestCategoriesCPtr s = cl.get<dbMeta::schemas::TestCategories>();
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

	SchemaSyncronizer ss;
	ss.init(cl.get<dbMeta::schemas::TestCategories>(), con, "_suf");
	TSyncLog log;
	ss.sync(log, true, true, true);
	return 0;
}

