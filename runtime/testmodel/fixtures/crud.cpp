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
	CPPUNIT_TEST( _furniture );
	CPPUNIT_TEST( _computer );

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


	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _furniture()
	{
		checkSchema();
		CPPUNIT_ASSERT_NO_THROW(_mod.con().once("BEGIN").exec().throwIfError());

		Furniture_ptr cat = _t->getFurniture();
		Furniture::Tuple tup;

		CPPUNIT_ASSERT(tup.id == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.constraints == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.depth == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.height == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.weight == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.width == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.cost == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.incomingDate == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.inventoryNumber == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.securityStatus == r3::fields::fvs_notset);

		Furniture::Tuple_ptr ptup;

		CPPUNIT_ASSERT_NO_THROW(cat->ins(tup));
		CPPUNIT_ASSERT(tup.id.fvs()==r3::fields::fvs_set);
		CPPUNIT_ASSERT(tup.id.value());

		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(tup.id));

		ptup->constraints = r3::fields::fvs_set;
		ptup->constraints.value().set(0);
		ptup->constraints.value().set(2);
		ptup->constraints.value().set(3);
		ptup->depth = 50;
		ptup->height = 40;
		ptup->weight = 30;
		ptup->width = 20;
		ptup->cost = 123.45;
		ptup->incomingDate = boost::gregorian::date(2011, 6, 2);
		ptup->inventoryNumber = "sdfgs";
		ptup->securityStatus = 1;
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));

		CPPUNIT_ASSERT(ptup->constraints == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->depth == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->height == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->weight == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->width == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->cost == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->incomingDate == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->inventoryNumber == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->securityStatus == r3::fields::fvs_set);

		CPPUNIT_ASSERT(ptup->constraints == std::bitset<8>(std::string("1101")));
		CPPUNIT_ASSERT(ptup->depth == 50);
		CPPUNIT_ASSERT(ptup->height == 40);
		CPPUNIT_ASSERT(ptup->weight == 30.0f);
		CPPUNIT_ASSERT(ptup->width == 20);
		CPPUNIT_ASSERT(ptup->cost == 12345);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber == "sdfgs");
		CPPUNIT_ASSERT(ptup->securityStatus == 1);


		/////////////////////////////////////////////////
		CPPUNIT_ASSERT_NO_THROW(_t->getStock()->del(ptup->id));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(!ptup);

		CPPUNIT_ASSERT_NO_THROW(_mod.con().once("ROLLBACK").exec().throwIfError());
	}



	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _computer()
	{
		checkSchema();
		CPPUNIT_ASSERT_NO_THROW(_mod.con().once("BEGIN").exec().throwIfError());

		Computer_ptr cat = _t->getComputer();
		Computer::Tuple tup;

		CPPUNIT_ASSERT(tup.id == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.equipmentInterval == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.equipmentStamp == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.mobile == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.model == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.cost == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.incomingDate == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.inventoryNumber == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.securityStatus == r3::fields::fvs_notset);

		Computer::Tuple_ptr ptup;

		CPPUNIT_ASSERT_NO_THROW(cat->ins(tup));
		CPPUNIT_ASSERT(tup.id.fvs()==r3::fields::fvs_set);
		CPPUNIT_ASSERT(tup.id.value());

		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(tup.id));

		ptup->equipmentInterval = pgc::DateTimeDuration(boost::gregorian::date_duration(15), boost::posix_time::time_duration(12,45,13));
		ptup->equipmentStamp = boost::posix_time::ptime(boost::gregorian::date(2003,04,15), boost::posix_time::time_duration(12,0,32,150000));
		ptup->mobile = false;
		ptup->model = "mmm";
		ptup->cost = 123.45;
		ptup->incomingDate = boost::gregorian::date(2011, 6, 2);
		ptup->inventoryNumber = "sdfgs";
		ptup->securityStatus = 1;
		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));

		CPPUNIT_ASSERT(ptup->id == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->equipmentInterval == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->equipmentStamp == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->mobile == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->model == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->cost == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->incomingDate == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->inventoryNumber == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->securityStatus == r3::fields::fvs_set);

		CPPUNIT_ASSERT(ptup->equipmentInterval == pgc::DateTimeDuration(boost::gregorian::date_duration(15), boost::posix_time::time_duration(12,45,13)));
		CPPUNIT_ASSERT(ptup->equipmentStamp == boost::posix_time::ptime(boost::gregorian::date(2003,04,15), boost::posix_time::time_duration(12,0,32,150000)));
		CPPUNIT_ASSERT(ptup->mobile == false);
		CPPUNIT_ASSERT(ptup->model == "mmm");
		CPPUNIT_ASSERT(ptup->cost == 12345);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber == "sdfgs");
		CPPUNIT_ASSERT(ptup->securityStatus == 1);


		/////////////////////////////////////////////////
		CPPUNIT_ASSERT_NO_THROW(_t->getStock()->del(ptup->id));
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(ptup));
		CPPUNIT_ASSERT(!ptup);

		CPPUNIT_ASSERT_NO_THROW(_mod.con().once("ROLLBACK").exec().throwIfError());
	}

};
CPPUNIT_TEST_SUITE_REGISTRATION( Crud );


//////////////////////////////////////////////////////////////////////////

