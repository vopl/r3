// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "litesql/expr.hpp"
#include <iostream>

#include "pgs/sugar.hpp"


int _tmain(int argc, _TCHAR* argv[])
{
	{
		using namespace pgs;

		Data<int> d1;

		Select s;
		s.set(Field<int>() == Value<int>(d1) || Value<int>(10) == Field<int>());

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

