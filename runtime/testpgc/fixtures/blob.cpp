#include "stdafx.h"
#include <cppunit/config/SourcePrefix.h>
#include <string>
#include "pgc/connection.hpp"
#include "pgc/exception.hpp"
#include "pgc/blob.hpp"


class Blob
	: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( Blob );
	CPPUNIT_TEST( connected );

	CPPUNIT_TEST( _blob );

	CPPUNIT_TEST_SUITE_END();

protected:
	pgc::Connection _con;

public:
	void setUp()
	{
		_con.open("dbname=test user=postgres password=postgres port=5432");
	}

	void tearDown()
	{
		_con.close();
	}

protected:
	void connected()
	{
		CPPUNIT_ASSERT( pgc::ecs_ok == _con.status());
	}
















	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _blob()
	{
		pgc::Blob bIn, bOut;

		bIn.con(_con);


		_con.once("BEGIN").exec().throwIfError();

		bIn.write("012345", 6);

		CPPUNIT_ASSERT_EQUAL(2, bIn.seek(2, pgc::bsm_set));
		CPPUNIT_ASSERT_EQUAL(2, bIn.tell());

		CPPUNIT_ASSERT_EQUAL(3, bIn.seek(1, pgc::bsm_cur));
		CPPUNIT_ASSERT_EQUAL(3, bIn.tell());

		CPPUNIT_ASSERT_EQUAL(4, bIn.seek(-2, pgc::bsm_end));
		CPPUNIT_ASSERT_EQUAL(4, bIn.tell());


		CPPUNIT_ASSERT_EQUAL(0, bIn.seek(0));
		char buf[256];
		CPPUNIT_ASSERT_EQUAL(6, bIn.read(buf, 8));
		CPPUNIT_ASSERT(!strncmp(buf, "0123456", 6));

		CPPUNIT_ASSERT(_con.once("SELECT $1::oid").exec(bIn).throwIfError().fetch(0,0,bOut));

		CPPUNIT_ASSERT_EQUAL(6, bOut.read(buf, 8));
		CPPUNIT_ASSERT(!strncmp(buf, "0123456", 6));

		CPPUNIT_ASSERT(bOut.truncate(4));
		CPPUNIT_ASSERT_EQUAL(0, bOut.seek(0));
		CPPUNIT_ASSERT_EQUAL(4, bOut.read(buf, 8));
		CPPUNIT_ASSERT(!strncmp(buf, "0123456", 4));

		char tmpbuf[MAX_PATH+1];
		{
			tmpnam(tmpbuf);
			std::ofstream ofs(tmpbuf);
			CPPUNIT_ASSERT(ofs);
			ofs<<"asdfgh";
			ofs.close();
		}

		CPPUNIT_ASSERT(bIn.import(tmpbuf));
		CPPUNIT_ASSERT_EQUAL(6, bIn.read(buf, 8));
		CPPUNIT_ASSERT(!strncmp(buf, "asdfgh", 6));

		{
			unlink(tmpbuf);
		}

		CPPUNIT_ASSERT(bIn.close());
		CPPUNIT_ASSERT_EQUAL(6, bIn.read(buf, 8));
		CPPUNIT_ASSERT(!strncmp(buf, "asdfgh", 6));

		CPPUNIT_ASSERT(bIn.unlink());
		CPPUNIT_ASSERT_EQUAL(0, bIn.read(NULL, 8));
		CPPUNIT_ASSERT(bIn.unlink());


		_con.once("ROLLBACK").exec().throwIfError();
	}



	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////



};
CPPUNIT_TEST_SUITE_REGISTRATION( Blob );


//////////////////////////////////////////////////////////////////////////

