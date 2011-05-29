// core.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "r3/model.hpp"
#include "pgc/connection.hpp"


int _tmain(int argc, _TCHAR* argv[])
{


	r3::Model m;


	pgc::Connection con;
	con.open("dbname=test user=postgres password=postgres port=5432");

// 	s->dbCon(con);
// 	try
// 	{
// 		s->dbDrop();
// 	}
// 	catch(std::exception &e)
// 	{
// 		std::cout<<e.what()<<std::endl;
// 	}
// 
// 	try
// 	{
// 		s->dbCreate();
// 	}
// 	catch(std::exception &e)
// 	{
// 		std::cout<<e.what()<<std::endl;
// 	}
	return 0;
}

