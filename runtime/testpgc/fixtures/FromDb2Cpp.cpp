#include "stdafx.h"
#include <cppunit/config/SourcePrefix.h>
#include <string>
#include "pgc/connection.hpp"


class FromDb2Cpp
	: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( FromDb2Cpp );
	CPPUNIT_TEST( connected );

	CPPUNIT_TEST( _pchar );
	CPPUNIT_TEST( _stdstring );
	CPPUNIT_TEST( _bool );
	CPPUNIT_TEST( _float );
	CPPUNIT_TEST( _double );

	CPPUNIT_TEST( _integral<boost::int8_t> );
	CPPUNIT_TEST( _integral<boost::int16_t> );
	CPPUNIT_TEST( _integral<boost::int32_t> );
	CPPUNIT_TEST( _integral<boost::int64_t> );
	CPPUNIT_TEST( _integral<boost::uint8_t> );
	CPPUNIT_TEST( _integral<boost::uint16_t> );
	CPPUNIT_TEST( _integral<boost::uint32_t> );
	CPPUNIT_TEST( _integral<boost::uint64_t> );

	CPPUNIT_TEST( _stdtm );

	CPPUNIT_TEST( _stdbitset );
	CPPUNIT_TEST( _stdvectorchar );

	CPPUNIT_TEST( _boost_date_time_date );
	CPPUNIT_TEST( _boost_date_time_ptime );
	CPPUNIT_TEST( _boost_date_time_datedur );
	CPPUNIT_TEST( _boost_date_time_timedur );
	CPPUNIT_TEST( _boost_date_time_datetimedur );

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
	void _pchar()
	{
		char buf[4096];
		char *val = buf;

#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)
#define STR_EQUAL(x,y) CPPUNIT_ASSERT_EQUAL( std::string(x), std::string(y) );

		CPPUNIT_ASSERT( SQL("-1234::int2") );
		STR_EQUAL( "-1234", val);

		CPPUNIT_ASSERT( SQL("-1234::int4") );
		STR_EQUAL( "-1234", val);

		CPPUNIT_ASSERT( SQL("-1234::int8") );
		STR_EQUAL( "-1234", val);

		CPPUNIT_ASSERT( SQL("-1234.1234::numeric(10,5)") );
		STR_EQUAL( "-1234.1234", val);

		CPPUNIT_ASSERT( SQL("-1234.1234::float4") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -1234.1234, atof(val), 1e-3);

		CPPUNIT_ASSERT( SQL("-1234.1234::float8") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -1234.1234, atof(val), 1e-3);

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

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp") );
		STR_EQUAL( "2010-03-04 13:00:17", val );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp with time zone") );
		//зависит от локальной зоны
		//STR_EQUAL( "2010-03-04 13:00:17", val );

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );
		STR_EQUAL( "4 month 5 day 18:07:56", val );

		CPPUNIT_ASSERT( SQL("'2010-03-04'::date") );
		STR_EQUAL( "2010-03-04", val );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time") );
		STR_EQUAL( "13:00:17", val );

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
	void _stdstring()
	{
		std::string val;

#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)
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

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp") );
		STR_EQUAL( "2010-03-04 13:00:17", val );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp with time zone") );
		//зависит от локальной зоны
		//STR_EQUAL( "2010-03-04 13:00:17", val );

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );
		STR_EQUAL( "4 month 5 day 18:07:56", val );

		CPPUNIT_ASSERT( SQL("'2010-03-04'::date") );
		STR_EQUAL( "2010-03-04", val );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time") );
		STR_EQUAL( "13:00:17", val );

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
	void _bool()
	{
		bool val;

#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( SQL("-123::int2") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("0::int4") );
		CPPUNIT_ASSERT_EQUAL( false, val );

		CPPUNIT_ASSERT( SQL("1::int8") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("-1234.321::numeric(10,5)") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("-1234.123::float4") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("-0::float8") );
		CPPUNIT_ASSERT_EQUAL( false, val );

		CPPUNIT_ASSERT( SQL("'1234'::money") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("''::varchar") );
		CPPUNIT_ASSERT_EQUAL( false, val );

		CPPUNIT_ASSERT( SQL("'1234'::char(10)") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("'1234'::text") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("'1234'::bytea") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( !SQL("'2010-03-04 13:00:17'::timestamp") );

		CPPUNIT_ASSERT( !SQL("'2010-03-04 13:00:17'::timestamp with time zone") );

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( !SQL("'2010-03-04'::date") );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time with time zone") );
		//зависит от локальной зоны
		//STR_EQUAL( "13:00:17", val );

		CPPUNIT_ASSERT( SQL("true") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("false") );
		CPPUNIT_ASSERT_EQUAL( false, val );

		CPPUNIT_ASSERT( SQL("B'101100111000'::bit(12)") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("B'0101100111000'::varbit") );
		CPPUNIT_ASSERT_EQUAL( false, val );

		CPPUNIT_ASSERT( SQL("B''::varbit") );
		CPPUNIT_ASSERT_EQUAL( false, val );


		CPPUNIT_ASSERT( SQL("B'1'::varbit") );
		CPPUNIT_ASSERT_EQUAL( true, val );
		CPPUNIT_ASSERT( SQL("B'11'::varbit") );
		CPPUNIT_ASSERT_EQUAL( true, val );
		CPPUNIT_ASSERT( SQL("B'111111'::varbit") );
		CPPUNIT_ASSERT_EQUAL( true, val );
		CPPUNIT_ASSERT( SQL("B'111111111111'::varbit") );
		CPPUNIT_ASSERT_EQUAL( true, val );

		CPPUNIT_ASSERT( SQL("B'01'::varbit") );
		CPPUNIT_ASSERT_EQUAL( false, val );
		CPPUNIT_ASSERT( SQL("B'011'::varbit") );
		CPPUNIT_ASSERT_EQUAL( false, val );
		CPPUNIT_ASSERT( SQL("B'0111111'::varbit") );
		CPPUNIT_ASSERT_EQUAL( false, val );
		CPPUNIT_ASSERT( SQL("B'0111111111111'::varbit") );
		CPPUNIT_ASSERT_EQUAL( false, val );

		CPPUNIT_ASSERT( SQL("1234::oid") );
		CPPUNIT_ASSERT_EQUAL( true, val );

	}














	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _float()
	{
		float val;

#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( SQL("-123::int2") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -123.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("0::int4") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("1::int8") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("-1234.321::numeric(10,5)") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -1234.321f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("-1234.123::float4") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -1234.123f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("-0::float8") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("'1234'::money") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 123400.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("''::varchar") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("'1234'::char(10)") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1234.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("'1234'::text") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1234.0f, val, 1e-5 );

		CPPUNIT_ASSERT( !SQL("'1234'::bytea") );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 3.2102280e+014f, val, 1e+10 );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp with time zone") );

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0865276e+013f, val, 1e+10 );

		CPPUNIT_ASSERT( SQL("'2010-03-04'::date") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 2455260.0, val, 1e-0 );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 4.6817001e+010, val, 1e+7 );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time with time zone") );

		CPPUNIT_ASSERT( SQL("true") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("false") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("B'000010000110000001111001111111'::bit(32)") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.23456f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("B'000'::varbit") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0f, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("B''::varbit") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0f, val, 1e-5 );


		CPPUNIT_ASSERT( SQL("1234::oid") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1234.0f, val, 1e-5 );

	}










	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _double()
	{
		double val;

#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( SQL("-123::int2") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -123.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("0::int4") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("1::int8") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("-1234.321::numeric(10,5)") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -1234.321, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("-1234.123::float4") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -1234.123, val, 1e-3 );

		CPPUNIT_ASSERT( SQL("-0::float8") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("'1234'::money") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 123400.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("''::varchar") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("'1234'::char(10)") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1234.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("'1234'::text") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1234.0, val, 1e-5 );

		CPPUNIT_ASSERT( !SQL("'1234'::bytea") );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 3.2102280e+014, val, 1e+10 );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp with time zone") );

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0865276e+013, val, 1e+10 );

		CPPUNIT_ASSERT( SQL("'2010-03-04'::date") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 2455260.0, val, 1e-0 );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 4.6817001e+010, val, 1e+7 );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time with time zone") );

		CPPUNIT_ASSERT( SQL("true") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("false") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("B'1000001100000011110011111111110000011100010011001111000100111111'::bit(64)") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -9.7285273740343379e+291, val, 1e+285 );

		CPPUNIT_ASSERT( SQL("B'000'::varbit") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0, val, 1e-5 );

		CPPUNIT_ASSERT( SQL("B''::varbit") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 0.0, val, 1e-5 );


		CPPUNIT_ASSERT( SQL("1234::oid") );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1234.0, val, 1e-5 );

	}

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	template <class T>
	void _integral()
	{
		T val;

#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( SQL("123::int2") );
		CPPUNIT_ASSERT_EQUAL( (T)123, val );

		CPPUNIT_ASSERT( SQL("0::int4") );
		CPPUNIT_ASSERT_EQUAL( (T)0, val );

		CPPUNIT_ASSERT( SQL("123::int8") );
		CPPUNIT_ASSERT_EQUAL( (T)123, val );

		CPPUNIT_ASSERT( SQL("123.321::numeric(10,5)") );
		CPPUNIT_ASSERT_EQUAL( (T)123, val );

		CPPUNIT_ASSERT( SQL("123.123::float4") );
		CPPUNIT_ASSERT_EQUAL( (T)123, val );

		CPPUNIT_ASSERT( SQL("123.5678::float8") );
		CPPUNIT_ASSERT_EQUAL( (T)123, val );

		CPPUNIT_ASSERT( SQL("'1'::money") );
		CPPUNIT_ASSERT_EQUAL( (T)100, val );

		CPPUNIT_ASSERT( SQL("''::varchar") );
		CPPUNIT_ASSERT_EQUAL( (T)0, val );

		CPPUNIT_ASSERT( SQL("'123'::char(10)") );
		CPPUNIT_ASSERT_EQUAL( (T)123, val );

		CPPUNIT_ASSERT( SQL("'123'::text") );
		CPPUNIT_ASSERT_EQUAL( (T)123, val );

		CPPUNIT_ASSERT( !SQL("'1234'::bytea") );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp") );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp with time zone") );

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );

		CPPUNIT_ASSERT( SQL("'2010-03-04'::date") );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time") );

		CPPUNIT_ASSERT( SQL("'13:00:17'::time with time zone") );

		CPPUNIT_ASSERT( SQL("true") );
		CPPUNIT_ASSERT_EQUAL( (T)1, val );

		CPPUNIT_ASSERT( SQL("false") );
		CPPUNIT_ASSERT_EQUAL( (T)0, val );

		CPPUNIT_ASSERT( SQL("B'1101111'::bit(7)") );
		CPPUNIT_ASSERT_EQUAL( (T)123, val );

		CPPUNIT_ASSERT( SQL("B'000'::varbit") );
		CPPUNIT_ASSERT_EQUAL( (T)0, val );

		CPPUNIT_ASSERT( SQL("B''::varbit") );
		CPPUNIT_ASSERT_EQUAL( (T)0, val );


		CPPUNIT_ASSERT( SQL("123::oid") );
		CPPUNIT_ASSERT_EQUAL( (T)123, val );
	}















	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _stdtm()
	{
		std::tm val;

#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( !SQL("-123::int2") );

		CPPUNIT_ASSERT( !SQL("0::int4") );

		CPPUNIT_ASSERT( !SQL("1::int8") );

		CPPUNIT_ASSERT( !SQL("-1234.321::numeric(10,5)") );

		CPPUNIT_ASSERT( !SQL("-1234.123::float4") );

		CPPUNIT_ASSERT( !SQL("-0::float8") );

		CPPUNIT_ASSERT( !SQL("'1234'::money") );

		CPPUNIT_ASSERT( !SQL("''::varchar") );

		CPPUNIT_ASSERT( !SQL("'1234'::char(10)") );

		CPPUNIT_ASSERT( !SQL("'1234'::text") );

		CPPUNIT_ASSERT( !SQL("'1234'::bytea") );

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp") );
		CPPUNIT_ASSERT_EQUAL( 17, val.tm_sec);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_min);
		CPPUNIT_ASSERT_EQUAL( 13, val.tm_hour);
		CPPUNIT_ASSERT_EQUAL( 4, val.tm_mday);
		CPPUNIT_ASSERT_EQUAL( 2, val.tm_mon);
		CPPUNIT_ASSERT_EQUAL( 110, val.tm_year);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_wday);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_yday);
		CPPUNIT_ASSERT_EQUAL( -1, val.tm_isdst);

		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp with time zone") );
		CPPUNIT_ASSERT_EQUAL( 17, val.tm_sec);
		//CPPUNIT_ASSERT_EQUAL( 0, val.tm_min);
		//CPPUNIT_ASSERT_EQUAL( 0, val.tm_hour);
		CPPUNIT_ASSERT_EQUAL( 4, val.tm_mday);
		CPPUNIT_ASSERT_EQUAL( 2, val.tm_mon);
		CPPUNIT_ASSERT_EQUAL( 110, val.tm_year);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_wday);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_yday);
		CPPUNIT_ASSERT_EQUAL( -1, val.tm_isdst);

		CPPUNIT_ASSERT( !SQL("'4 months 5 days 18:07:56'::interval") );

		CPPUNIT_ASSERT( SQL("'2010-03-04'::date") );
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_sec);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_min);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_hour);
		CPPUNIT_ASSERT_EQUAL( 4, val.tm_mday);
		CPPUNIT_ASSERT_EQUAL( 2, val.tm_mon);
		CPPUNIT_ASSERT_EQUAL( 110, val.tm_year);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_wday);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_yday);
		CPPUNIT_ASSERT_EQUAL( -1, val.tm_isdst);

		CPPUNIT_ASSERT( SQL("'13:00:17'::time") );
		CPPUNIT_ASSERT_EQUAL( 17, val.tm_sec);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_min);
		CPPUNIT_ASSERT_EQUAL( 13, val.tm_hour);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_mday);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_mon);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_year);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_wday);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_yday);
		CPPUNIT_ASSERT_EQUAL( -1, val.tm_isdst);

		CPPUNIT_ASSERT( SQL("'13:00:17'::time with time zone") );
		CPPUNIT_ASSERT_EQUAL( 17, val.tm_sec);
// 		CPPUNIT_ASSERT_EQUAL( 0, val.tm_min);
// 		CPPUNIT_ASSERT_EQUAL( 13, val.tm_hour);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_mday);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_mon);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_year);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_wday);
		CPPUNIT_ASSERT_EQUAL( 0, val.tm_yday);
		CPPUNIT_ASSERT_EQUAL( -1, val.tm_isdst);

		CPPUNIT_ASSERT( !SQL("true") );

		CPPUNIT_ASSERT( !SQL("false") );

		CPPUNIT_ASSERT( !SQL("B'1000001100000011110011111111110000011100010011001111000100111111'::bit(64)") );

		CPPUNIT_ASSERT( !SQL("B'000'::varbit") );
		CPPUNIT_ASSERT( !SQL("1234::oid") );
	}













	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _stdbitset()
	{
		std::bitset<8> val8;
		std::bitset<16> val16;
		std::bitset<32> val32;
		std::bitset<64> val64;
		std::bitset<128> val128;
		std::bitset<256> val256;
		std::bitset<512> val512;

#undef SQL
#define SQL(x, v) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,v)

		CPPUNIT_ASSERT( !SQL("-123::int2", val8) );
		CPPUNIT_ASSERT( !SQL("0::int4", val8) );
		CPPUNIT_ASSERT( !SQL("1::int8", val8) );
		CPPUNIT_ASSERT( !SQL("-1234.321::numeric(10,5)", val8) );
		CPPUNIT_ASSERT( !SQL("-1234.123::float4", val8) );
		CPPUNIT_ASSERT( !SQL("-0::float8", val8) );
		CPPUNIT_ASSERT( !SQL("'1234'::money", val8) );
		CPPUNIT_ASSERT( !SQL("''::varchar", val8) );
		CPPUNIT_ASSERT( !SQL("'1234'::char(10)", val8) );
		CPPUNIT_ASSERT( !SQL("'1234'::text", val8) );






		CPPUNIT_ASSERT( SQL("'1234'::bytea", val8) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<8>(std::string("00110001")), val8);

		CPPUNIT_ASSERT( SQL("'1234'::bytea", val16) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<16>(std::string("0011001000110001")), val16);

		CPPUNIT_ASSERT( SQL("'1234'::bytea", val32) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<32>(std::string("00110100001100110011001000110001")), val32);

		val64.set(47);
		CPPUNIT_ASSERT( SQL("'1234'::bytea", val64) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<64>(std::string("00110100001100110011001000110001")), val64);

		val128.set(100);
		CPPUNIT_ASSERT( SQL("'1234'::bytea", val128) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<128>(std::string("00110100001100110011001000110001")), val128);

		val256.set(255);
		CPPUNIT_ASSERT( SQL("'1234'::bytea", val256) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<256>(std::string("00110100001100110011001000110001")), val256);

		val512.set(67);
		val512.set(75);
		val512.set(100);
		val512.set(200);
		val512.set(300);
		val512.set(400);
		val512.set(511);
		CPPUNIT_ASSERT( SQL("'1234'::bytea", val512) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<512>(std::string("00110100001100110011001000110001")), val512);


		CPPUNIT_ASSERT( SQL("'D234'::bytea", val8) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<8>(std::string("01000100")), val8);

		CPPUNIT_ASSERT( SQL("'#'::bytea", val8) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<8>(std::string("00100011")), val8);








		CPPUNIT_ASSERT( SQL("B'1000001100000011110011111111110000011100010011001111000100111111'::bit(64)", val8) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<8>(std::string("11000001")), val8);

		CPPUNIT_ASSERT( SQL("B'000'::varbit", val8) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<8>(std::string("00000000")), val8);

		CPPUNIT_ASSERT( SQL("B'001'::varbit", val8) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<8>(std::string("00000100")), val8);

		CPPUNIT_ASSERT( SQL("B'10100'::varbit", val8) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<8>(std::string("00000101")), val8);

		CPPUNIT_ASSERT( SQL("B''::varbit", val8) );
		CPPUNIT_ASSERT_EQUAL(std::bitset<8>(std::string("00000000")), val8);







		CPPUNIT_ASSERT( !SQL("'2010-03-04 13:00:17'::timestamp", val8) );
		CPPUNIT_ASSERT( !SQL("'2010-03-04 13:00:17'::timestamp with time zone", val8) );
		CPPUNIT_ASSERT( !SQL("'4 months 5 days 18:07:56'::interval", val8) );
		CPPUNIT_ASSERT( !SQL("'2010-03-04'::date", val8) );
		CPPUNIT_ASSERT( !SQL("'13:00:17'::time", val8) );
		CPPUNIT_ASSERT( !SQL("'13:00:17'::time with time zone", val8) );
		CPPUNIT_ASSERT( !SQL("true", val8) );
		CPPUNIT_ASSERT( !SQL("false", val8) );

		CPPUNIT_ASSERT( !SQL("1234::oid", val8) );
	}


























	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _stdvectorchar()
	{
		std::vector<unsigned char> val;

#undef SQL
#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( !SQL("-123::int2") );
		CPPUNIT_ASSERT( !SQL("0::int4") );
		CPPUNIT_ASSERT( !SQL("1::int8") );
		CPPUNIT_ASSERT( !SQL("-1234.321::numeric(10,5)") );
		CPPUNIT_ASSERT( !SQL("-1234.123::float4") );
		CPPUNIT_ASSERT( !SQL("-0::float8") );
		CPPUNIT_ASSERT( !SQL("'1234'::money") );


		val.resize(10);
		CPPUNIT_ASSERT( SQL("''::varchar") );
		CPPUNIT_ASSERT(val.size() == 0);

		std::vector<unsigned char> expect;
		CPPUNIT_ASSERT( SQL("'1234'::varchar") );

		expect.resize(4);
		expect[0] = '1';
		expect[1] = '2';
		expect[2] = '3';
		expect[3] = '4';

		CPPUNIT_ASSERT( SQL("'1234'::bytea") );
		CPPUNIT_ASSERT(expect == val);

		CPPUNIT_ASSERT( SQL("B'1001011'::varbit") );
		expect.resize(1);
		expect[0] = 0x69;
		CPPUNIT_ASSERT(expect == val);


		CPPUNIT_ASSERT( SQL("B'1001011011010110000'::varbit") );
		expect.resize(3);
		expect[0] = 0x69;
		expect[1] = 0x6b;
		expect[2] = 0x00;
		CPPUNIT_ASSERT(expect == val);




		CPPUNIT_ASSERT( !SQL("'2010-03-04 13:00:17'::timestamp") );
		CPPUNIT_ASSERT( !SQL("'2010-03-04 13:00:17'::timestamp with time zone") );
		CPPUNIT_ASSERT( !SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT( !SQL("'2010-03-04'::date") );
		CPPUNIT_ASSERT( !SQL("'13:00:17'::time") );
		CPPUNIT_ASSERT( !SQL("'13:00:17'::time with time zone") );
		CPPUNIT_ASSERT( !SQL("true") );
		CPPUNIT_ASSERT( !SQL("false") );

		CPPUNIT_ASSERT( !SQL("1234::oid") );
	}






















	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _boost_date_time_date()
	{
		boost::gregorian::date val;

#undef SQL
#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( !SQL("-123::int2") );
		CPPUNIT_ASSERT( !SQL("0::int4") );
		CPPUNIT_ASSERT( !SQL("1::int8") );
		CPPUNIT_ASSERT( !SQL("-1234.321::numeric(10,5)") );
		CPPUNIT_ASSERT( !SQL("-1234.123::float4") );
		CPPUNIT_ASSERT( !SQL("-0::float8") );
		CPPUNIT_ASSERT( !SQL("'1234'::money") );
		CPPUNIT_ASSERT( !SQL("''::varchar") );
		CPPUNIT_ASSERT( !SQL("'1234'::bytea") );
		CPPUNIT_ASSERT( !SQL("B'1001011'::varbit") );




		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17'::timestamp") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)2010, (unsigned short)val.year());
		CPPUNIT_ASSERT_EQUAL((unsigned short)3, (unsigned short)val.month());
		CPPUNIT_ASSERT_EQUAL((unsigned short)4, (unsigned short)val.day());

		CPPUNIT_ASSERT( SQL("'2011-04-05 13:00:17'::timestamp with time zone") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)2011, (unsigned short)val.year());
		CPPUNIT_ASSERT_EQUAL((unsigned short)4, (unsigned short)val.month());
		CPPUNIT_ASSERT_EQUAL((unsigned short)5, (unsigned short)val.day());

		CPPUNIT_ASSERT( SQL("'2012-05-06'::date") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)2012, (unsigned short)val.year());
		CPPUNIT_ASSERT_EQUAL((unsigned short)5, (unsigned short)val.month());
		CPPUNIT_ASSERT_EQUAL((unsigned short)6, (unsigned short)val.day());




		CPPUNIT_ASSERT( !SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT( !SQL("'13:00:17'::time") );
		CPPUNIT_ASSERT( !SQL("'13:00:17'::time with time zone") );
		CPPUNIT_ASSERT( !SQL("true") );
		CPPUNIT_ASSERT( !SQL("false") );
		CPPUNIT_ASSERT( !SQL("1234::oid") );
	}



















	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _boost_date_time_ptime()
	{
		boost::posix_time::ptime val;

#undef SQL
#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( !SQL("-123::int2") );
		CPPUNIT_ASSERT( !SQL("0::int4") );
		CPPUNIT_ASSERT( !SQL("1::int8") );
		CPPUNIT_ASSERT( !SQL("-1234.321::numeric(10,5)") );
		CPPUNIT_ASSERT( !SQL("-1234.123::float4") );
		CPPUNIT_ASSERT( !SQL("-0::float8") );
		CPPUNIT_ASSERT( !SQL("'1234'::money") );
		CPPUNIT_ASSERT( !SQL("''::varchar") );
		CPPUNIT_ASSERT( !SQL("'1234'::bytea") );
		CPPUNIT_ASSERT( !SQL("B'1001011'::varbit") );




		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17.27452'::timestamp") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)2010, (unsigned short)val.date().year());
		CPPUNIT_ASSERT_EQUAL((unsigned short)3, (unsigned short)val.date().month());
		CPPUNIT_ASSERT_EQUAL((unsigned short)4, (unsigned short)val.date().day());

		CPPUNIT_ASSERT_EQUAL((unsigned short)13, (unsigned short)val.time_of_day().hours());
		CPPUNIT_ASSERT_EQUAL((unsigned short)0, (unsigned short)val.time_of_day().minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)17, (unsigned short)val.time_of_day().seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)274520, val.time_of_day().fractional_seconds());

		CPPUNIT_ASSERT( SQL("'2012-05-05 13:00:17.99'::timestamp with time zone") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)2012, (unsigned short)val.date().year());
		CPPUNIT_ASSERT_EQUAL((unsigned short)5, (unsigned short)val.date().month());
		CPPUNIT_ASSERT_EQUAL((unsigned short)5, (unsigned short)val.date().day());
// 		CPPUNIT_ASSERT_EQUAL((unsigned short)13, (unsigned short)val.time_of_day().hours());
// 		CPPUNIT_ASSERT_EQUAL((unsigned short)0, (unsigned short)val.time_of_day().minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)17, (unsigned short)val.time_of_day().seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)990000, val.time_of_day().fractional_seconds());


		CPPUNIT_ASSERT( SQL("'2012-05-06'::date") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)2012, (unsigned short)val.date().year());
		CPPUNIT_ASSERT_EQUAL((unsigned short)5, (unsigned short)val.date().month());
		CPPUNIT_ASSERT_EQUAL((unsigned short)6, (unsigned short)val.date().day());
		CPPUNIT_ASSERT_EQUAL((unsigned short)0, (unsigned short)val.time_of_day().hours());
		CPPUNIT_ASSERT_EQUAL((unsigned short)0, (unsigned short)val.time_of_day().minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)0, (unsigned short)val.time_of_day().seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)0, val.time_of_day().fractional_seconds());



		CPPUNIT_ASSERT( !SQL("'13:00:17'::time") );
		CPPUNIT_ASSERT( !SQL("'13:00:17'::time with time zone") );

		CPPUNIT_ASSERT( !SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT( !SQL("true") );
		CPPUNIT_ASSERT( !SQL("false") );
		CPPUNIT_ASSERT( !SQL("1234::oid") );
	}





















	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _boost_date_time_datedur()
	{
		boost::gregorian::date_duration val;

#undef SQL
#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( !SQL("-123::int2") );
		CPPUNIT_ASSERT( !SQL("0::int4") );
		CPPUNIT_ASSERT( !SQL("1::int8") );
		CPPUNIT_ASSERT( !SQL("-1234.321::numeric(10,5)") );
		CPPUNIT_ASSERT( !SQL("-1234.123::float4") );
		CPPUNIT_ASSERT( !SQL("-0::float8") );
		CPPUNIT_ASSERT( !SQL("'1234'::money") );
		CPPUNIT_ASSERT( !SQL("''::varchar") );
		CPPUNIT_ASSERT( !SQL("'1234'::bytea") );
		CPPUNIT_ASSERT( !SQL("B'1001011'::varbit") );




		CPPUNIT_ASSERT( !SQL("'2010-03-04 13:00:17.27452'::timestamp") );
		CPPUNIT_ASSERT( !SQL("'2012-05-05 13:00:17.99'::timestamp with time zone") );
		CPPUNIT_ASSERT( !SQL("'2012-05-06'::date") );
		CPPUNIT_ASSERT( !SQL("'13:00:17'::time") );
		CPPUNIT_ASSERT( !SQL("'13:00:17'::time with time zone") );

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT_EQUAL((long)4*30 + 5, val.days());

		CPPUNIT_ASSERT( SQL("'18:07:56'::interval") );
		CPPUNIT_ASSERT_EQUAL((long)0, val.days());


		CPPUNIT_ASSERT( !SQL("true") );
		CPPUNIT_ASSERT( !SQL("false") );
		CPPUNIT_ASSERT( !SQL("1234::oid") );
	}
























	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _boost_date_time_timedur()
	{
		boost::posix_time::time_duration val;

#undef SQL
#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( !SQL("-123::int2") );
		CPPUNIT_ASSERT( !SQL("0::int4") );
		CPPUNIT_ASSERT( !SQL("1::int8") );
		CPPUNIT_ASSERT( !SQL("-1234.321::numeric(10,5)") );
		CPPUNIT_ASSERT( !SQL("-1234.123::float4") );
		CPPUNIT_ASSERT( !SQL("-0::float8") );
		CPPUNIT_ASSERT( !SQL("'1234'::money") );
		CPPUNIT_ASSERT( !SQL("''::varchar") );
		CPPUNIT_ASSERT( !SQL("'1234'::bytea") );
		CPPUNIT_ASSERT( !SQL("B'1001011'::varbit") );




		CPPUNIT_ASSERT( SQL("'2010-03-04 13:00:17.27452'::timestamp") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)13, (unsigned short)val.hours());
		CPPUNIT_ASSERT_EQUAL((unsigned short)0, (unsigned short)val.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)17, (unsigned short)val.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)274520, val.fractional_seconds());

		CPPUNIT_ASSERT( SQL("'2012-05-05 13:00:17.99'::timestamp with time zone") );
// 		CPPUNIT_ASSERT_EQUAL((unsigned short)13, (unsigned short)val.hours());
// 		CPPUNIT_ASSERT_EQUAL((unsigned short)0, (unsigned short)val.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)17, (unsigned short)val.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)990000, val.fractional_seconds());

		CPPUNIT_ASSERT( !SQL("'2012-05-06'::date") );
		
		CPPUNIT_ASSERT( SQL("'14:01:18'::time") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)14, (unsigned short)val.hours());
		CPPUNIT_ASSERT_EQUAL((unsigned short)1, (unsigned short)val.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)18, (unsigned short)val.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)0, val.fractional_seconds());

		CPPUNIT_ASSERT( SQL("'14:01:18.67'::time with time zone") );
// 		CPPUNIT_ASSERT_EQUAL((unsigned short)14, (unsigned short)val.hours());
// 		CPPUNIT_ASSERT_EQUAL((unsigned short)1, (unsigned short)val.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)18, (unsigned short)val.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)670000, val.fractional_seconds());

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)18, (unsigned short)val.hours());
		CPPUNIT_ASSERT_EQUAL((unsigned short)7, (unsigned short)val.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)56, (unsigned short)val.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)0, val.fractional_seconds());

		CPPUNIT_ASSERT( SQL("'19:08:59.22'::interval") );
		CPPUNIT_ASSERT_EQUAL((unsigned short)19, (unsigned short)val.hours());
		CPPUNIT_ASSERT_EQUAL((unsigned short)8, (unsigned short)val.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)59, (unsigned short)val.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)220000, val.fractional_seconds());


		CPPUNIT_ASSERT( !SQL("true") );
		CPPUNIT_ASSERT( !SQL("false") );
		CPPUNIT_ASSERT( !SQL("1234::oid") );
	}

























	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _boost_date_time_datetimedur()
	{
		pgc::DateTimeDuration val;

#undef SQL
#define SQL(x) _con.once().sql("SELECT " x "").exec().throwIfError().fetch(0,0,val)

		CPPUNIT_ASSERT( !SQL("-123::int2") );
		CPPUNIT_ASSERT( !SQL("0::int4") );
		CPPUNIT_ASSERT( !SQL("1::int8") );
		CPPUNIT_ASSERT( !SQL("-1234.321::numeric(10,5)") );
		CPPUNIT_ASSERT( !SQL("-1234.123::float4") );
		CPPUNIT_ASSERT( !SQL("-0::float8") );
		CPPUNIT_ASSERT( !SQL("'1234'::money") );
		CPPUNIT_ASSERT( !SQL("''::varchar") );
		CPPUNIT_ASSERT( !SQL("'1234'::bytea") );
		CPPUNIT_ASSERT( !SQL("B'1001011'::varbit") );




		CPPUNIT_ASSERT( !SQL("'2010-03-04 13:00:17.27452'::timestamp") );
		CPPUNIT_ASSERT( !SQL("'2012-05-05 13:00:17.99'::timestamp with time zone") );
		CPPUNIT_ASSERT( !SQL("'2012-05-06'::date") );

		CPPUNIT_ASSERT( SQL("'14:01:18'::time") );
		CPPUNIT_ASSERT_EQUAL((long)0, val._dd.days());
		CPPUNIT_ASSERT_EQUAL((unsigned short)14, (unsigned short)val._td.hours());
		CPPUNIT_ASSERT_EQUAL((unsigned short)1, (unsigned short)val._td.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)18, (unsigned short)val._td.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)0, val._td.fractional_seconds());

		CPPUNIT_ASSERT( SQL("'14:01:18.67'::time with time zone") );
		CPPUNIT_ASSERT_EQUAL((long)0, val._dd.days());
// 		CPPUNIT_ASSERT_EQUAL((unsigned short)14, (unsigned short)val._td.hours());
// 		CPPUNIT_ASSERT_EQUAL((unsigned short)1, (unsigned short)val._td.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)18, (unsigned short)val._td.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)670000, val._td.fractional_seconds());

		CPPUNIT_ASSERT( SQL("'4 months 5 days 18:07:56'::interval") );
		CPPUNIT_ASSERT_EQUAL((long)4*30+5, val._dd.days());
		CPPUNIT_ASSERT_EQUAL((unsigned short)18, (unsigned short)val._td.hours());
		CPPUNIT_ASSERT_EQUAL((unsigned short)7, (unsigned short)val._td.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)56, (unsigned short)val._td.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)0, val._td.fractional_seconds());

		CPPUNIT_ASSERT( SQL("'19:08:59.22'::interval") );
		CPPUNIT_ASSERT_EQUAL((long)0, val._dd.days());
		CPPUNIT_ASSERT_EQUAL((unsigned short)19, (unsigned short)val._td.hours());
		CPPUNIT_ASSERT_EQUAL((unsigned short)8, (unsigned short)val._td.minutes());
		CPPUNIT_ASSERT_EQUAL((unsigned short)59, (unsigned short)val._td.seconds());
		CPPUNIT_ASSERT_EQUAL((boost::int64_t)220000, val._td.fractional_seconds());


		CPPUNIT_ASSERT( !SQL("true") );
		CPPUNIT_ASSERT( !SQL("false") );
		CPPUNIT_ASSERT( !SQL("1234::oid") );
	}



	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////



};
CPPUNIT_TEST_SUITE_REGISTRATION( FromDb2Cpp );


//////////////////////////////////////////////////////////////////////////

