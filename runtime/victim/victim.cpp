// victim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "dbMeta/manager.hpp"
#include "dbMeta/schemas/TestCategories.hpp"

#include "pgc/connection.hpp"


void dumpCategory(dbMeta::CategoryPtr p)
{
	cerr<<"category: "<<p->getName()<<endl;
}

void dumpSchema(dbMeta::SchemaPtr p)
{
	cerr<<"schema: "<<p->getName()<<endl;

	const dbMeta::CategoryPtrs &cats = p->getCategories();

	cerr<<"categories: "<<cats.size()<<endl;

	BOOST_FOREACH(dbMeta::CategoryPtr c, cats)
	{
		dumpCategory(p->getCategory(c->getName()));
	}

}

//////////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	dbMeta::Manager man;

	man.add<dbMeta::schemas::TestCategories>();

	pgc::Connection con;
	//con.log(std::cerr, pgc::lf_all);
	con.open("dbname=test user=postgres password=postgres port=5432");
	if(pgc::ecs_ok != con.status())
	{
		cerr<<"db con failed!";
		return -1;
	}

	pgc::Statement s = con.prep("SELECT id, $1 FROM t_club");
	pgc::Statement s2 = con.prep("UPDATE t_club SET id=id+1");
	con.once("BEGIN").exec().throwIfError();
	time_t t;
	time(&t);
	for(size_t i(0); i<10000;i++)
	{
		s2.exec().throwIfError();
		int in=220,out1=380, out2=380;
		pgc::Result r = s.bind(in).exec().throwIfError();
		r.fetch(0,0,out1);
		r.fetch(0,1,out2);
	}
	time_t t2;
	time(&t2);
	cerr<<t2-t;
	return 0;


	cerr<<"chemas: "<<man.getSchemas().size()<<endl;

	BOOST_FOREACH(dbMeta::SchemaPtr s, man.getSchemas())
	{
		dumpSchema(man.getSchema(s->getName()));
	}
	return 0;
}

