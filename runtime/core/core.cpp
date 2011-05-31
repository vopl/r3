// core.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "r3/model.hpp"
#include "pgc/connection.hpp"


int _tmain(int argc, _TCHAR* argv[])
{


	r3::Model m;

	m.startInThread("dbname=test user=postgres password=postgres port=5432");

	m.con().log(std::cout, pgc::lf_exec);

	m.stm<int>("sdf").sql("SELECT 1").exec();
	m.stm("sdf").sql("SELECT 1").exec();

	r3::model::Test_ptr c2 = m.getTest("myId");

	c2->stm<int>("sdf").sql("SELECT 1").exec();
	c2->stm("sdf").sql("SELECT 1").exec();

// 	try
// 	{
// 		c2->dbDrop();
// 	}
// 	catch(std::exception &e)
// 	{
// 		std::cout<<e.what()<<std::endl;
// 	}


	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	m.con().once("BEGIN").exec();
	try
	{

		int cnt;
		m.con().once("SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name=$1").exec("Test_myId").throwIfError().fetch(0,0,cnt);

		if(!cnt)
		{
			c2->dbCreate();
		}
		m.con().once("COMMIT").exec();
	}
	catch(std::exception &e)
	{
		m.con().once("ROLLBACK").exec();
		std::cout<<e.what()<<std::endl;
	}

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	m.con().once("BEGIN").exec();
	try
	{
		r3::model::Test_ptr test = m.getTest("myId");

		r3::model::s_Test::Computer_ptr ccomp = test->getComputer();

		ccomp->stm<int>("sdf").sql("SELECT 1").exec();
		ccomp->stm("sdf").sql("SELECT 1").exec();

 		r3::model::s_Test::Computer::Tuple comp;

		comp.mobile = true;
		comp.model = "mmodel!!";
 		ccomp->ins(comp);
		comp.model = "mmodel2!!";
		ccomp->ins(comp);
		comp.model = "mmodel3!!";
		ccomp->ins(comp);

		comp.model = "mmodel3!!___";
		ccomp->upd(comp);
//		ccomp->del(comp);

// 		comp.cost = 340;
// 		ccomp->upd(comp);
// 
		r3::model::s_Test::Computer::Tuple_ptr pcomp;
 		pcomp = ccomp->sel(comp.id);

		r3::model::s_Test::Stock_ptr cstock = test->getStock();
		r3::model::s_Test::Stock::Tuple_ptr pstock;
 		pstock = cstock->sel(comp.id);
 		//pcomp->upg(pstock);
 
 		cstock->del(pstock);

		m.con().once("COMMIT").exec();
	}
	catch(std::exception &e)
	{
		m.con().once("ROLLBACK").exec();
		std::cout<<e.what()<<std::endl;
	}

	m.stopInThread();

	return 0;
}

