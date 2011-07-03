// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "litesql/expr.hpp"
#include <iostream>

#include "pgs/sugar.hpp"
#include "pgs/value.hpp"
#include "pgs/field.hpp"

#include "../src/pgs/statementImpl.hpp"
#include "../src/pgs/exprAccess.hpp"

struct SS
{

};

int _tmain(int argc, _TCHAR* argv[])
{
	{
		using namespace pgs;

		Value v1;
		Field f1("fn1", "tn1", "sn1", "tid1");
		Field f2("fn2", "tn2", "sn2", "tid2");

		Expr e = f1 == v1 || Value(10) == f2 && Value(2)==any(f2) && v1==any(f2);

		StatementImpl s;

		s.addExpr(ExprAccess(e));
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

