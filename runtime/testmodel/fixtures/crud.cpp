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
	CPPUNIT_TEST( _forFields );

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
	void _forFields()
	{
		checkSchema();
		CPPUNIT_ASSERT_NO_THROW(_mod.con().once("BEGIN").exec().throwIfError());

		Derived4fields_ptr cat = _t->getDerived4fields();
		Derived4fields::Tuple tup;

		CPPUNIT_ASSERT(tup.id == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Bool == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Binary == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Date == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.DateTimeInterval == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Enum1 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Enum2 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.File == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Image == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Int16 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Int32 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Int64 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Int8 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Money == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Real32 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Real64 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Set1 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Set2 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.String == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Time == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Timestamp == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Video == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Audiod == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Boold == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.DateTimeIntervald == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Dated == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Enum1d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Enum2d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Filed == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Imaged == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Int16d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Int32d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Int64d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Int8d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Moneyd == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Real32d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Real64d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Set1d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Set2d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Stringd == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Timed == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Timestampd == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(tup.Videod == r3::fields::fvs_notset);



		//////////////////////////////////////////////////////////////////////////
		Derived4fields::Tuple_ptr ptup;

		CPPUNIT_ASSERT_NO_THROW(cat->ins(tup));
		CPPUNIT_ASSERT(tup.id.fvs()==r3::fields::fvs_set);
		CPPUNIT_ASSERT(tup.id.value());

		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(tup.id));

		CPPUNIT_ASSERT(ptup->Audio == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Binary == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Bool == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Date == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->DateTimeInterval == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Enum1 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Enum2 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->File == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Image == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Int16 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Int32 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Int64 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Int8 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Money == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Real32 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Real64 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Set1 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Set2 == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->String == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Time == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Timestamp == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Video == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Audiod == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Boold == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->DateTimeIntervald == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Dated == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Enum1d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Enum2d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Filed == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Imaged == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Int16d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Int32d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Int64d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Int8d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Moneyd == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Real32d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Real64d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Set1d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Set2d == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Stringd == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Timed == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Timestampd == r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->Videod == r3::fields::fvs_null);

		*ptup = Derived4fields::Tuple();

		CPPUNIT_ASSERT(ptup->id == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Audio == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Binary == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Bool == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Date == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->DateTimeInterval == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Enum1 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Enum2 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->File == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Image == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Int16 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Int32 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Int64 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Int8 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Money == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Real32 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Real64 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Set1 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Set2 == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->String == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Time == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Timestamp == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Video == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Audiod == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Boold == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->DateTimeIntervald == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Dated == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Enum1d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Enum2d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Filed == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Imaged == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Int16d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Int32d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Int64d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Int8d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Moneyd == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Real32d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Real64d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Set1d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Set2d == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Stringd == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Timed == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Timestampd == r3::fields::fvs_notset);
		CPPUNIT_ASSERT(ptup->Videod == r3::fields::fvs_notset);

		//////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////
		ptup->id = tup.id;
		ptup->Audio = r3::fields::fvs_set;
		ptup->Audio.name() = "asd";
		ptup->Audio.ext() = "fds";
		ptup->Audio.blob().con(_mod.con());
		ptup->Audio.blob().write("qwert", 5);

		ptup->Binary = r3::fields::fvs_set;
		ptup->Binary.value().resize(3);
		ptup->Binary.value()[0] = '0';
		ptup->Binary.value()[1] = '1';
		ptup->Binary.value()[2] = '2';
		ptup->Bool = true;
		ptup->Date = boost::gregorian::date(2015, 5, 5);
		ptup->DateTimeInterval = pgc::DateTimeDuration(boost::gregorian::date_duration(178), boost::posix_time::time_duration(134, 12, 32));
		ptup->Enum1 = 4;
		ptup->Enum2 = 5;
		ptup->File = r3::fields::fvs_set;
		ptup->File.name() = "asdf";
		ptup->File.ext() = "fdsa";
		ptup->File.blob().con(_mod.con());
		ptup->File.blob().write("qwerty", 6);

		ptup->Image = r3::fields::fvs_set;
		ptup->Image.name() = "asdf1";
		ptup->Image.ext() = "fdsa1";
		ptup->Image.blob().con(_mod.con());
		ptup->Image.blob().write("qwerty1", 7);
		ptup->Image.width() = 10;
		ptup->Image.height() = 30;

		ptup->Int16 = 22;
		ptup->Int32 = 222;
		ptup->Int64 = 2222;
		ptup->Int8 = 2;
		ptup->Money = 120;
		ptup->Real32 = 1.84;
		ptup->Real64 = 1.85;
		ptup->Set1 = r3::fields::fvs_set;
		ptup->Set1.value().set(0);
		ptup->Set1.value().set(2);
		ptup->Set1.value().set(4);

		ptup->Set2 = r3::fields::fvs_set;
		ptup->Set2.value().set(0);
		ptup->Set2.value().set(2);
		ptup->Set2.value().set(4);

		ptup->String ="zxcv";
		ptup->Time = boost::posix_time::time_duration(13, 13, 32);
		ptup->Timestamp = boost::posix_time::ptime(boost::gregorian::date(2045, 2, 12), boost::posix_time::time_duration(11, 11, 33));
		ptup->Video = r3::fields::fvs_set;
		ptup->Video.name() = "asdf12";
		ptup->Video.ext() = "fdsa12";
		ptup->Video.blob().con(_mod.con());
		ptup->Video.blob().write("qwerty12", 8);
		ptup->Video.width() = 102;
		ptup->Video.height() = 302;

		ptup->Audiod = r3::fields::fvs_set;
		ptup->Audiod.name() = "asd";
		ptup->Audiod.ext() = "fds";
		ptup->Audiod.blob().con(_mod.con());
		ptup->Audiod.blob().write("qwert", 5);

		ptup->Boold = true;
		ptup->Dated = boost::gregorian::date(2015, 5, 5);
		ptup->DateTimeIntervald = pgc::DateTimeDuration(boost::gregorian::date_duration(178), boost::posix_time::time_duration(134, 12, 32));
		ptup->Enum1d = 4;
		ptup->Enum2d = 5;
		ptup->Filed = r3::fields::fvs_set;
		ptup->Filed.name() = "asdf";
		ptup->Filed.ext() = "fdsa";
		ptup->Filed.blob().con(_mod.con());
		ptup->Filed.blob().write("qwerty", 6);

		ptup->Imaged = r3::fields::fvs_set;
		ptup->Imaged.name() = "asdf1";
		ptup->Imaged.ext() = "fdsa1";
		ptup->Imaged.blob().con(_mod.con());
		ptup->Imaged.blob().write("qwerty1", 7);
		ptup->Imaged.width() = 10;
		ptup->Imaged.height() = 30;

		ptup->Int16d = 22;
		ptup->Int32d = 222;
		ptup->Int64d = 2222;
		ptup->Int8d = 2;
		ptup->Moneyd = 120;
		ptup->Real32d = 1.84;
		ptup->Real64d = 1.85;
		ptup->Set1d = r3::fields::fvs_set;
		ptup->Set1d.value().set(0);
		ptup->Set1d.value().set(2);
		ptup->Set1d.value().set(4);

		ptup->Set2d = r3::fields::fvs_set;
		ptup->Set2d.value().set(0);
		ptup->Set2d.value().set(2);
		ptup->Set2d.value().set(4);

		ptup->Stringd ="zxcv";
		ptup->Timed = boost::posix_time::time_duration(13, 13, 32);
		ptup->Timestampd = boost::posix_time::ptime(boost::gregorian::date(2045, 2, 12), boost::posix_time::time_duration(11, 11, 33));
		ptup->Videod = r3::fields::fvs_set;
		ptup->Videod.name() = "asdf12";
		ptup->Videod.ext() = "fdsa12";
		ptup->Videod.blob().con(_mod.con());
		ptup->Videod.blob().write("qwerty12", 8);
		ptup->Videod.width() = 102;
		ptup->Videod.height() = 302;

		CPPUNIT_ASSERT_NO_THROW(cat->upd(ptup));

		*ptup = Derived4fields::Tuple();
		CPPUNIT_ASSERT_NO_THROW(ptup = cat->sel(tup.id));

		CPPUNIT_ASSERT(ptup->Audio == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->Audio.name() == "asd");
		CPPUNIT_ASSERT(ptup->Audio.ext() == "fds");

		CPPUNIT_ASSERT(ptup->Binary == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->Binary.value().size() == 3);
		CPPUNIT_ASSERT(ptup->Binary.value()[0] == '0');
		CPPUNIT_ASSERT(ptup->Binary.value()[1] == '1');
		CPPUNIT_ASSERT(ptup->Binary.value()[2] == '2');
		CPPUNIT_ASSERT(ptup->Bool == true);
		CPPUNIT_ASSERT(ptup->Date == boost::gregorian::date(2015, 5, 5));
		CPPUNIT_ASSERT(ptup->DateTimeInterval == pgc::DateTimeDuration(boost::gregorian::date_duration(178), boost::posix_time::time_duration(134, 12, 32)));
		CPPUNIT_ASSERT(ptup->Enum1 == 4);
		CPPUNIT_ASSERT(ptup->Enum2 == 5);
		CPPUNIT_ASSERT(ptup->File == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->File.name() == "asdf");
		CPPUNIT_ASSERT(ptup->File.ext() == "fdsa");

		CPPUNIT_ASSERT(ptup->Image == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->Image.name() == "asdf1");
		CPPUNIT_ASSERT(ptup->Image.ext() == "fdsa1");
		CPPUNIT_ASSERT(ptup->Image.width() == 10);
		CPPUNIT_ASSERT(ptup->Image.height() == 30);

		CPPUNIT_ASSERT(ptup->Int16 == 22);
		CPPUNIT_ASSERT(ptup->Int32 == 222);
		CPPUNIT_ASSERT(ptup->Int64 == 2222);
		CPPUNIT_ASSERT(ptup->Int8 == 2);
		CPPUNIT_ASSERT(ptup->Money == 120);

		CPPUNIT_ASSERT(ptup->Real32 == r3::fields::fvs_set);
		CPPUNIT_ASSERT_DOUBLES_EQUAL(ptup->Real32.value(), 1.84, 1e-5);
		CPPUNIT_ASSERT(ptup->Real64 == r3::fields::fvs_set);
		CPPUNIT_ASSERT_DOUBLES_EQUAL(ptup->Real64.value(), 1.85, 1e-5);
		CPPUNIT_ASSERT(ptup->Set1 == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->Set1 == std::bitset<8>(std::string("10101")));

		CPPUNIT_ASSERT(ptup->Set2 == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->Set2 == std::bitset<16>(std::string("10101")));

		CPPUNIT_ASSERT(ptup->String =="zxcv");
		CPPUNIT_ASSERT(ptup->Time == boost::posix_time::time_duration(13, 13, 32));
		CPPUNIT_ASSERT(ptup->Timestamp == boost::posix_time::ptime(boost::gregorian::date(2045, 2, 12), boost::posix_time::time_duration(11, 11, 33)));
		CPPUNIT_ASSERT(ptup->Video == r3::fields::fvs_set);
		CPPUNIT_ASSERT(ptup->Video.name() == "asdf12");
		CPPUNIT_ASSERT(ptup->Video.ext() == "fdsa12");
		CPPUNIT_ASSERT(ptup->Video.width() == 102);
		CPPUNIT_ASSERT(ptup->Video.height() == 302);


		CPPUNIT_ASSERT_NO_THROW(_mod.con().once("ROLLBACK").exec().throwIfError());
	}

};
CPPUNIT_TEST_SUITE_REGISTRATION( Crud );


//////////////////////////////////////////////////////////////////////////

