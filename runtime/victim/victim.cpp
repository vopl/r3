// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "litesql/expr.hpp"
using namespace litesql;
#include <iostream>

namespace pgc
{
	class Result
	{
	};
	class Executor
	{

	};
}
namespace sql
{
	//////////////////////////////////////////////////////////////////////////
	class Element
	{
	public:
		pgc::Result exec(pgc::Executor executor);
	};
	//////////////////////////////////////////////////////////////////////////
	class Where
	{
	public:
		Where and(Where) const
		{
			return Where();
		}
		Where or(Where) const
		{
			return Where();
		}
	};

	//////////////////////////////////////////////////////////////////////////
	class Value
	{
	public:
		Where eq(const Value &v) const
		{
			return Where();
		}
		Where ne(const Value &v) const
		{
			return Where();
		}
		Where gt(const Value &v) const
		{
			return Where();
		}
		Where lt(const Value &v) const
		{
			return Where();
		}
	};

	//////////////////////////////////////////////////////////////////////////
	class Field
		: public Value
	{
		string _table;
		string _name;
	};

	Where operator==(const Value &v1, const Value &v2)
	{
		return v1.eq(v2);
	}

	Where operator||(const Where &v1, const Where &v2)
	{
		return v1.or(v2);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	{
		using namespace sql;

		Value v1, v2;
		(v1 == v2) || (v2 == v1);
	}

	FieldType f1("f1", "typ1", "tbl1");
	FieldType f2("f2", "typ2", "tbl2");

	std::cout<<(f1 == 2 || f2.like("22")).asString()<<std::endl;
	return 0;
}

