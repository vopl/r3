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
	class Query
	{
		//what
		Where _w;
		//orderBy, limitOffset, 
	public:
		pgc::Result exec(pgc::Executor executor);

		Query set(Where e){return *this;}

// 		Query set(What e){return *this;}
// 		Query set(OrderBy d){return *this;}
// 		Query set(LimitOffset e){return *this;}

	};

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	class Atom
	{
	public:
		Where eq(const Atom &v) const
		{
			return Where();
		}
		Where ne(const Atom &v) const
		{
			return Where();
		}
		Where gt(const Atom &v) const
		{
			return Where();
		}
		Where lt(const Atom &v) const
		{
			return Where();
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	class Data
	{
	public:
		Data(...)
		{

		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	class Value
		: public Atom<CppType>
	{
		Data<CppType> _data;
	public:
		Value(const CppType &ref)
			: _data(ref)
		{
		}
		Value(Data<CppType> data)
			: _data(data)
		{
		}
	};

	//////////////////////////////////////////////////////////////////////////
	template <class CppType>
	class Field
		: public Atom<CppType>
	{
		string _table;
		string _name;
	public:
		Field()
		{
		}
	};

	Where operator==(const Atom<int> &v1, const Atom<int> &v2)
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

		sql::Data<int> d1;

		Query q;
		q.set(sql::Field<int>() == sql::Value<int>(d1) || sql::Value<int>(10) == sql::Field<int>());

		//d1.set(220);
		//q.exec(executor)
	}

	FieldType f1("f1", "typ1", "tbl1");
	FieldType f2("f2", "typ2", "tbl2");

	std::cout<<(f1 == 2 || f2.like("22")).asString()<<std::endl;
	return 0;
}

