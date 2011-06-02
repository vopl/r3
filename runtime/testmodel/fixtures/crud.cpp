#include "stdafx.h"
#include <cppunit/config/SourcePrefix.h>
#include <string>
#include "r3/model.hpp"

using namespace r3::model::s_Test;


class Crud
	: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( Crud );
	CPPUNIT_TEST( connected );

	CPPUNIT_TEST( _stock );

	CPPUNIT_TEST_SUITE_END();

protected:
	r3::Model _mod;

	r3::model::Test_ptr _t;


public:
	void setUp()
	{
		_mod.startInThread("dbname=test user=postgres password=postgres port=5432");
		_t = _mod.getTest("crudTester");
		_mod.con().log(std::cout, pgc::lf_all);
	}

	void tearDown()
	{
		_t.reset();
		_mod.stopInThread();
	}

protected:
	void connected()
	{
		CPPUNIT_ASSERT( pgc::ecs_ok == _mod.con().status());
	}










	void checkSchema()
	{
		size_t cnt(0);
		CPPUNIT_ASSERT_NO_THROW(
			_mod.con().once("SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name=$1").exec(std::string("Test_crudTester")).throwIfError().fetch(0,0,cnt)
			);
		if(!cnt)
		{
			CPPUNIT_ASSERT_NO_THROW(_t->dbCreate());
		}
	}








	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _stock()
	{
		checkSchema();
		CPPUNIT_ASSERT_NO_THROW(_mod.con().once("BEGIN").exec().throwIfError());

		Stock_ptr cat = _t->getStock();
		Stock::Tuple tup;
		Stock::Tuple_ptr ptup;

		CPPUNIT_ASSERT_NO_THROW(cat->ins(tup));
		CPPUNIT_ASSERT(tup.id.fvs()==r3::fields::fvs_set);
		CPPUNIT_ASSERT(tup.id.value());

		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(tup.id));
		CPPUNIT_ASSERT(ptup->id == tup.id);
		CPPUNIT_ASSERT(ptup->cost.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->incomingDate.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->inventoryNumber.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(ptup->cost.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->incomingDate.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->inventoryNumber.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		ptup->cost = 200;
		ptup->incomingDate = r3::fields::fvs_notset;
		ptup->inventoryNumber = r3::fields::fvs_notset;
		ptup->securityStatus = r3::fields::fvs_notset;
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(ptup->cost == 200);
		CPPUNIT_ASSERT(ptup->incomingDate.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->inventoryNumber.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		ptup->incomingDate = boost::gregorian::date(2011, 6, 2);
		ptup->inventoryNumber = r3::fields::fvs_notset;
		ptup->securityStatus = r3::fields::fvs_notset;
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(ptup->cost == 200);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		ptup->inventoryNumber = "asdfgh";
		ptup->securityStatus = r3::fields::fvs_notset;
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(ptup->cost == 200);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber == "asdfgh");
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		ptup->securityStatus = 2;
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(ptup->cost == 200);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber == "asdfgh");
		CPPUNIT_ASSERT(ptup->securityStatus == 2);

		///////////////////////////////////////////////
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(ptup->cost == 200);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber == "asdfgh");
		CPPUNIT_ASSERT(ptup->securityStatus == 2);


		///////////////////////////////////////////////
		ptup->cost = r3::fields::fvs_null;
		ptup->incomingDate = r3::fields::fvs_notset;
		ptup->inventoryNumber = r3::fields::fvs_null;
		ptup->securityStatus = r3::fields::fvs_notset;
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(ptup->cost.fvs() == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus == 2);

		ptup->cost = r3::fields::fvs_null;
		ptup->incomingDate = r3::fields::fvs_null;
		ptup->inventoryNumber = r3::fields::fvs_null;
		ptup->securityStatus = r3::fields::fvs_null;
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(ptup->cost.fvs() == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->incomingDate == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->inventoryNumber == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus == r3::fields::fvs_null);


		/////////////////////////////////////////////////
		CPPUNIT_ASSERT_NO_THROW(cat->del(ptup->id));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(!ptup);

		CPPUNIT_ASSERT_NO_THROW(_mod.con().once("ROLLBACK").exec().throwIfError());
	}


};
CPPUNIT_TEST_SUITE_REGISTRATION( Crud );


//////////////////////////////////////////////////////////////////////////

