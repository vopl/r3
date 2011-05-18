#include "stdafx.h"
#include <cppunit/config/SourcePrefix.h>
#include <string>
#include "pgc/connection.hpp"


class FromDb2Cpp
	: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( FromDb2Cpp );
	CPPUNIT_TEST( connected );
	CPPUNIT_TEST( pchar );

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

	void pchar()
	{
		char buf[4096];
		char *pchar = buf;

#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,pchar)
#define CPPUNIT_ASSERT_STR_EQUAL(x,y) CPPUNIT_ASSERT_EQUAL( std::string(x), std::string(y) );

		CPPUNIT_ASSERT( SQL("-1234::int2") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "-1234");

		CPPUNIT_ASSERT( SQL("-1234::int4") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "-1234");

		CPPUNIT_ASSERT( SQL("-1234::int8") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "-1234");

		CPPUNIT_ASSERT( SQL("-1234.1234::numeric(10,5)") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "-1234.1234");

		CPPUNIT_ASSERT( SQL("-1234.1234::float4") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( atof(pchar), -1234.1234, 1e-3);

		CPPUNIT_ASSERT( SQL("-1234.1234::float8") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( atof(pchar), -1234.1234, 1e-3);

		CPPUNIT_ASSERT( SQL("'1234'::money") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "123400");

		CPPUNIT_ASSERT( SQL("'1234'::varchar") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "1234");

		CPPUNIT_ASSERT( SQL("'1234'::char(10)") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "1234      ");

		CPPUNIT_ASSERT( SQL("'1234'::text") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "1234");

		CPPUNIT_ASSERT( SQL("'1234'::bytea") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "1234");

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "2010-03-04 13:00:17");

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp with time zone") );
		//зависит от локальной зоны
		//CPPUNIT_ASSERT_STR_EQUAL( pchar, "2010-03-04 13:00:17");

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "4 month 5 day 18:07:56");

		CPPUNIT_ASSERT( SQL("'2010-03-04'::date") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "2010-03-04");

		CPPUNIT_ASSERT( SQL("'13:00:17'::time") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "13:00:17");

		CPPUNIT_ASSERT( SQL("'13:00:17'::time with time zone") );
		//зависит от локальной зоны
		//CPPUNIT_ASSERT_STR_EQUAL( pchar, "13:00:17");

		CPPUNIT_ASSERT( SQL("true") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "1");

		CPPUNIT_ASSERT( SQL("B'101100111000'::bit(12)") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "101100111000");

		CPPUNIT_ASSERT( SQL("B'101100111000'::varbit") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "101100111000");

		CPPUNIT_ASSERT( SQL("1234::oid") );
		CPPUNIT_ASSERT_STR_EQUAL( pchar, "1234");

	}

};
CPPUNIT_TEST_SUITE_REGISTRATION( FromDb2Cpp );


//////////////////////////////////////////////////////////////////////////

