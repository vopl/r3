// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "dbMeta/manager.hpp"
#include "dbMeta/schemas/TestCategories.hpp"





//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	dbMeta::Manager man;

	man.add<dbMeta::schemas::TestCategories>();
	return 0;
}

