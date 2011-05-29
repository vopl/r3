// core.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "r3/model.hpp"
#include "pgc/connection.hpp"


int _tmain(int argc, _TCHAR* argv[])
{


	r3::Model m;

	m.startInThread("dbname=test user=postgres password=postgres port=5432");

	m.con().log(std::cout, pgc::lf_all);

	r3::model::common2_ptr c2 = m.getcommon2("myId");

	try
	{
		c2->dbDrop();
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	try
	{
		c2->dbCreate();
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	m.stopInThread();

	return 0;
}

