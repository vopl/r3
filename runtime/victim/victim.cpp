// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "litesql/expr.hpp"
using namespace litesql;
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	FieldType f1("f1", "typ1", "tbl1");
	FieldType f2("f2", "typ2", "tbl2");

	std::cout<<(f1 == 2).asString()<<std::endl;
	return 0;
}

