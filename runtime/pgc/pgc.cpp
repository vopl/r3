// pgc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "connection.hpp"
#include "exception.hpp"

int _tmain(int argc, _TCHAR* argv[])
{
	pgc::Connection con;
	con.open("dbname=test user=postgres password=postgres");

	std::string str;

	try
	{
// 		int i;
// 		con.once().sql("SELECT $1::varchar")
// 			.bind(i)
// 			.bind(220)
// 			.bind(std::string("sdfgsd"))
// 			.bind(str)
// 			.exec().fetch(str);
// 		;

		pgc::Result res = con.once().sql("SELECT '$1'::varchar").exec().throwIfError();

		for(size_t row(0); row<res.rows(); row++)
		{
			char *tmp = "init";
			res.fetch(row, (size_t)0, tmp);
		}
		
		;
	}
	catch (pgc::Exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	con.close();

	return 0;
}

