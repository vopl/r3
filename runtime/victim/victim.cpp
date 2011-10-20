// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "dbMeta/manager.hpp"
#include "dbMeta/schemas/TestCategories.hpp"

#include "pgc/connection.hpp"



//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	dbMeta::Manager man;

	const dbMeta::schemas::TestCategories &tc = man.add<dbMeta::schemas::TestCategories>();

	//tc.Furniture.cost;
	tc.ContractSimple.param4._category._schema.Stock.index_Index._category;

	pgc::Connection con;
	//con.log(std::cerr, pgc::lf_all);
	con.open("dbname=test user=postgres password=postgres port=5432");
	if(pgc::ecs_ok != con.status())
	{
		cerr<<"db con failed!";
		return -1;
	}

	return 0;
}

