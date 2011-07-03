// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "litesql/expr.hpp"
#include <iostream>

#include "pgs/sugar.hpp"
#include "pgs/value.hpp"
#include "pgs/field.hpp"

#include "pgs/select.hpp"

struct SS
{


};

int _tmain(int argc, _TCHAR* argv[])
{
	{
		using namespace pgs;

		Value v1("v1");
		Field f1("fn1", "tn1", "sn1", "tid1");
		Field f2("fn2", "tn2", "sn2", "tid2");

		Expr e = f1 == v1 || AValue(10) == f2 && AValue(2)==any(f2) && v1==any(f2);

		Select s((f1, f2, f2, AValue(20), v1));

		s.where(e);
		s.orderBy(e==AValue(220));
		s.compile();

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

