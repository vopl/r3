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

	r3::model::Test_ptr c2 = m.getTest("myId");

	try
	{
		c2->dbDrop();
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}


	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	m.con().once("BEGIN").exec();
	try
	{
		c2->dbCreate();
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

 		r3::model::s_Test::Computer::Tuple comp;

		//ccomp->
		comp.mobile = true;
// 		ccomp->ins(comp);
// 
// 		comp.cost = 340;
// 		ccomp->upd(comp);
// 
		r3::model::s_Test::Computer::Tuple_ptr pcomp;
// 		pcomp = ccomp->sel(comp.id);

		r3::model::s_Test::Stock_ptr cstock = test->getStock();
		r3::model::s_Test::Stock::Tuple_ptr pstock;
// 		pstock = cstock->sel(comp.id);
// 		pcomp->upg(pstock);
// 
// 		test->del(pcomp->id);

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

