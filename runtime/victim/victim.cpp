// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "litesql/expr.hpp"
#include <iostream>

#include "pgs/sugar.hpp"

struct SS
{

};

int _tmain(int argc, _TCHAR* argv[])
{
	{
		using namespace pgs;

		Value<int> v1;
		Field<int> f1("fn1", "tn1", "sn1", "tid1");
		Field<int> f2("fn2", "tn2", "sn2", "tid2");

		Select s;
		s.set( f1 == v1 || Value<int>(10) == f2);

		//d1.set(220);
		//s.bind(executor)
	}

	{
		using namespace litesql;

		FieldType f1("f1", "typ1", "tbl1");
		FieldType f2("f2", "typ2", "tbl2");

		std::cout<<(f1 == 2 || f2.like("22")).asString()<<std::endl;
	}
	return 0;
}

