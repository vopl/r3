#include "stdafx.h"
#include <cppunit/config/SourcePrefix.h>
#include <string>
#include "pgc/connection.hpp"


class Variant
	: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( Variant );
	CPPUNIT_TEST( connected );

	CPPUNIT_TEST( _stdstring );

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
	void _stdstring()
	{
		std::string val;

#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(val,0,0)
#define STR_EQUAL(x,y) CPPUNIT_ASSERT_EQUAL( std::string(x), y );

		CPPUNIT_ASSERT( SQL("-123::int2") );
		STR_EQUAL( "-123", val );

		CPPUNIT_ASSERT( SQL("-123::int4") );
		STR_EQUAL( "-123", val );

		CPPUNIT_ASSERT( SQL("-1234::int8") );
		STR_EQUAL( "-1234", val );

		CPPUNIT_ASSERT( SQL("-1234.321::numeric(10,5)") );
		STR_EQUAL( "-1234.321", val );

		CPPUNIT_ASSERT( SQL("-1234.123::float4") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -1234.123, atof(val.c_str()), 1e-3);

		CPPUNIT_ASSERT( SQL("-1234.1234::float8") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -1234.1234, atof(val.c_str()), 1e-3);

		CPPUNIT_ASSERT( SQL("'1234'::money") );
		STR_EQUAL( "123400", val );

		CPPUNIT_ASSERT( SQL("'1234'::varchar") );
		STR_EQUAL( "1234", val );

		CPPUNIT_ASSERT( SQL("'1234'::char(10)") );
		STR_EQUAL( "1234      ", val );

		CPPUNIT_ASSERT( SQL("'1234'::text") );
		STR_EQUAL( "1234", val );

		CPPUNIT_ASSERT( SQL("'1234'::bytea") );
		STR_EQUAL( "1234", val );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17.1234'::timestamp") );
		STR_EQUAL( "2010-03-04 13:00:17.1234", val );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp with time zone") );
		//зависит от локальной зоны
		//STR_EQUAL( "2010-03-04 13:00:17", val );

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56.4321'::interval") );
		STR_EQUAL( "4 month 5 day 18:07:56.4321", val );

		CPPUNIT_ASSERT( SQL("'2010-03-04'::date") );
		STR_EQUAL( "2010-03-04", val );

		CPPUNIT_ASSERT( SQL("'13:00:17.0012'::time") );
		STR_EQUAL( "13:00:17.0012", val );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time with time zone") );
		//зависит от локальной зоны
		//STR_EQUAL( "13:00:17", val );

		CPPUNIT_ASSERT( SQL("true") );
		STR_EQUAL( "1", val );

		CPPUNIT_ASSERT( SQL("B'101100111000'::bit(12)") );
		STR_EQUAL( "101100111000", val );

		CPPUNIT_ASSERT( SQL("B'101100111000'::varbit") );
		STR_EQUAL( "101100111000", val );

		CPPUNIT_ASSERT( SQL("1234::oid") );
		STR_EQUAL( "1234", val );

#undef STR_EQUAL

	}







	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////



};
CPPUNIT_TEST_SUITE_REGISTRATION( Variant );


//////////////////////////////////////////////////////////////////////////

