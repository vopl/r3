// core.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "r3/model.hpp"
#include "pgc/connection.hpp"


int _tmain(int argc, _TCHAR* argv[])
{


	r3::Model m;

	m.startInThread("dbname=test user=postgres password=postgres port=5432");

	m.con().log(std::cout, pgc::lf_exec);

	r3::model::Test_ptr c2 = m.getTest("myId");

	try
	{
		c2->dbDrop();
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}


	m.con().once("BEGIN").exec();
	try
	{
		c2->dbCreate();
		m.con().once("COMMIT").exec();
	}
	catch(std::exception &e)
	{
		m.con().once("ROLLBACK").exec();
		std::cout<<e.what()<<std::endl;
	}

	m.stopInThread();

	return 0;
}

