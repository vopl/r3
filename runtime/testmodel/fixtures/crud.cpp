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

//	CPPUNIT_TEST( _ins );
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
	void _ins()
	{
		checkSchema();

		CPPUNIT_ASSERT_NO_THROW(_t->getPeople()->ins(People::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getClient()->ins(Client::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getEmployee()->ins(Employee::Tuple()));

		CPPUNIT_ASSERT_NO_THROW(_t->getStock()->ins(Stock::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getFurniture()->ins(Furniture::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getComputer()->ins(Computer::Tuple()));

		CPPUNIT_ASSERT_NO_THROW(_t->getServicePart()->ins(ServicePart::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getWebSite()->ins(WebSite::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getProgram()->ins(Program::Tuple()));


		CPPUNIT_ASSERT_NO_THROW(_t->getDocument()->ins(Document::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getLetter()->ins(Letter::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getContract()->ins(Contract::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getContractComplex()->ins(ContractComplex::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getContractSimple()->ins(ContractSimple::Tuple()));
		CPPUNIT_ASSERT_NO_THROW(_t->getMockup()->ins(Mockup::Tuple()));





		CPPUNIT_ASSERT_NO_THROW(_t->getPeople()->ins(People::Tuple_ptr(new People::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getClient()->ins(Client::Tuple_ptr(new Client::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getEmployee()->ins(Employee::Tuple_ptr(new Employee::Tuple)));

		CPPUNIT_ASSERT_NO_THROW(_t->getStock()->ins(Stock::Tuple_ptr(new Stock::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getFurniture()->ins(Furniture::Tuple_ptr(new Furniture::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getComputer()->ins(Computer::Tuple_ptr(new Computer::Tuple)));

		CPPUNIT_ASSERT_NO_THROW(_t->getServicePart()->ins(ServicePart::Tuple_ptr(new ServicePart::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getWebSite()->ins(WebSite::Tuple_ptr(new WebSite::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getProgram()->ins(Program::Tuple_ptr(new Program::Tuple)));


		CPPUNIT_ASSERT_NO_THROW(_t->getDocument()->ins(Document::Tuple_ptr(new Document::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getLetter()->ins(Letter::Tuple_ptr(new Letter::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getContract()->ins(Contract::Tuple_ptr(new Contract::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getContractComplex()->ins(ContractComplex::Tuple_ptr(new ContractComplex::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getContractSimple()->ins(ContractSimple::Tuple_ptr(new ContractSimple::Tuple)));
		CPPUNIT_ASSERT_NO_THROW(_t->getMockup()->ins(Mockup::Tuple_ptr(new Mockup::Tuple)));


		////////////////////////////////////////////////////////
		{
			People::Tuple people;
			CPPUNIT_ASSERT_NO_THROW(_t->getPeople()->ins(people));

			CPPUNIT_ASSERT(people.id.fvs() == r3::fields::fvs_set);
			CPPUNIT_ASSERT(people.id.value() != 0);
		}

		////////////////////////////////////////////////////////
		{
			_mod.con().once("BEGIN").exec().throwIfError();
			Employee::Tuple t;
			t.birth = boost::gregorian::date(2011, 1, 12);
			t.department = 1;
			t.middlename = "mname";
			t.name = "name";
			t.photo.fvs(r3::fields::fvs_set);
			t.photo.name() = "pname";
			t.photo.ext() = "jpg";
			t.photo.blob().con(_mod.con());
			t.photo.blob().write("asdfg", 5);
			t.photo.width() = 220;
			t.photo.height() = 380;
			t.rateNight = 10012;
			t.rateNormal = 54.12;
			t.sex = 0;
			t.surname = "sname";

			Employee::Tuple t2(t);

			_t->getEmployee()->ins(t2);

			t.birth.fvs(r3::fields::fvs_null);
			t.department.fvs(r3::fields::fvs_null);
			t.middlename.fvs(r3::fields::fvs_null);
			t.name.fvs(r3::fields::fvs_null);
			t.photo.fvs(r3::fields::fvs_null);
			t.rateNight.fvs(r3::fields::fvs_null);
			t.rateNormal.fvs(r3::fields::fvs_null);
			t.sex.fvs(r3::fields::fvs_null);
			t.surname.fvs(r3::fields::fvs_null);
			_t->getEmployee()->ins(t);

			_mod.con().once("COMMIT").exec().throwIfError();

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

		ptup = cat->sel(tup.id);

		CPPUNIT_ASSERT(ptup->id == tup.id);
		CPPUNIT_ASSERT(ptup->cost.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->incomingDate.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->inventoryNumber.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		cat->upd(ptup);
		ptup = cat->sel(ptup);
		CPPUNIT_ASSERT(ptup->cost.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->incomingDate.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->inventoryNumber.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		ptup->cost = 200;
		ptup->incomingDate = r3::fields::fvs_notset;
		ptup->inventoryNumber = r3::fields::fvs_notset;
		ptup->securityStatus = r3::fields::fvs_notset;
		cat->upd(ptup);
		ptup = cat->sel(ptup);
		CPPUNIT_ASSERT(ptup->cost == 200);
		CPPUNIT_ASSERT(ptup->incomingDate.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->inventoryNumber.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		ptup->incomingDate = boost::gregorian::date(2011, 6, 2);
		ptup->inventoryNumber = r3::fields::fvs_notset;
		ptup->securityStatus = r3::fields::fvs_notset;
		cat->upd(ptup);
		ptup = cat->sel(ptup);
		CPPUNIT_ASSERT(ptup->cost == 200);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber.fvs()==r3::fields::fvs_null);
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		ptup->inventoryNumber = "asdfgh";
		ptup->securityStatus = r3::fields::fvs_notset;
		cat->upd(ptup);
		ptup = cat->sel(ptup);
		CPPUNIT_ASSERT(ptup->cost == 200);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber == "asdfgh");
		CPPUNIT_ASSERT(ptup->securityStatus.fvs()==r3::fields::fvs_null);

		///////////////////////////////////////////////
		ptup->securityStatus = 2;
		cat->upd(ptup);
		ptup = cat->sel(ptup);
		CPPUNIT_ASSERT(ptup->cost == 200);
		CPPUNIT_ASSERT(ptup->incomingDate == boost::gregorian::date(2011, 6, 2));
		CPPUNIT_ASSERT(ptup->inventoryNumber == "asdfgh");
		CPPUNIT_ASSERT(ptup->securityStatus == 2);


		/////////////////////////////////////////////////
		cat->del(ptup->id);
		ptup = cat->sel(ptup);
		CPPUNIT_ASSERT(!ptup);

		CPPUNIT_ASSERT_NO_THROW(_mod.con().once("ROLLBACK").exec().throwIfError());
	}


};
CPPUNIT_TEST_SUITE_REGISTRATION( Crud );


//////////////////////////////////////////////////////////////////////////

