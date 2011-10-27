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

//////////////////////////////////////////////////////////////////////////

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
	}

	{
		dbMeta::schemas::TestCategoriesCPtr s = cl.get<dbMeta::schemas::TestCategories>();
		s->Contract->file->_name;

		int k=220;
	}
	return 0;
}

