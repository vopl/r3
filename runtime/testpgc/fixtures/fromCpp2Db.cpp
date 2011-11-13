#include "stdafx.h"
#include <cppunit/config/SourcePrefix.h>
#include <string>
#include "pgc/connection.hpp"
#include "pgc/exception.hpp"


class FromCpp2Db
	: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( FromCpp2Db );
	CPPUNIT_TEST( connected );

	CPPUNIT_TEST( _bind );

	CPPUNIT_TEST_SUITE_END();

protected:
	pgc::Connection _con;

public:
	void setUp()
	{
		_con.open("dbname=test user=postgres password=postgres port=5432");
		_con.log(std::cerr, pgc::lf_none);
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
	void _bind()
	{
		std::string res;

#undef SQL
#define SQL(x, val) _con.once().sql("SELECT " x).bind(val).exec().throwIfError().fetch(res,0,0)

		CPPUNIT_ASSERT( SQL("$1::varchar", std::string("sdflgjkwer")) );
		CPPUNIT_ASSERT_EQUAL( std::string("sdflgjkwer"), res );



		CPPUNIT_ASSERT( SQL("$1::bool", true) );
		CPPUNIT_ASSERT_EQUAL( std::string("1"), res );
		CPPUNIT_ASSERT( SQL("$1::bool", false) );
		CPPUNIT_ASSERT_EQUAL( std::string("0"), res );





		CPPUNIT_ASSERT( SQL("$1::float4", 1.2345f) );
		CPPUNIT_ASSERT_EQUAL( std::string("1.2345"), res );

		CPPUNIT_ASSERT( SQL("$1::float8", 4.321) );
		CPPUNIT_ASSERT_EQUAL( std::string("4.321"), res );





		CPPUNIT_ASSERT( SQL("$1::int8", boost::int8_t(27)) );
		CPPUNIT_ASSERT_EQUAL( std::string("27"), res );

		CPPUNIT_ASSERT( SQL("$1::int8", boost::int16_t(-9835)) );
		CPPUNIT_ASSERT_EQUAL( std::string("-9835"), res );

		CPPUNIT_ASSERT( SQL("$1::int8", boost::int32_t(73458739)) );
		CPPUNIT_ASSERT_EQUAL( std::string("73458739"), res );

		CPPUNIT_ASSERT( SQL("$1::int8", boost::int64_t(7562976524)) );
		CPPUNIT_ASSERT_EQUAL( std::string("7562976524"), res );

		CPPUNIT_ASSERT( SQL("$1::int8", boost::uint8_t(27)) );
		CPPUNIT_ASSERT_EQUAL( std::string("27"), res );

		CPPUNIT_ASSERT( SQL("$1::int8", boost::uint16_t(9835)) );
		CPPUNIT_ASSERT_EQUAL( std::string("9835"), res );

		CPPUNIT_ASSERT( SQL("$1::int8", boost::uint32_t(73458739)) );
		CPPUNIT_ASSERT_EQUAL( std::string("73458739"), res );

		CPPUNIT_ASSERT( SQL("$1::int8", boost::uint64_t(7562976524)) );
		CPPUNIT_ASSERT_EQUAL( std::string("7562976524"), res );

		//too big for int8
		std::cout<<"now error message, is ok: ";
		CPPUNIT_ASSERT_THROW( SQL("$1::int8", boost::uint64_t(0xf000000000000000ULL)), pgc::Exception);

		CPPUNIT_ASSERT( SQL("$1::varchar", boost::uint64_t(0xf000000000000001ULL)) );
		CPPUNIT_ASSERT_EQUAL( std::string("17293822569102704641"), res );





		std::tm stm = {};
		stm.tm_sec = 22;
		stm.tm_min = 43;
		stm.tm_hour = 11;
		stm.tm_mday = 21;
		stm.tm_mon = 4;
		stm.tm_year = 111;
		CPPUNIT_ASSERT( SQL("$1::timestamp", stm ) );
		CPPUNIT_ASSERT_EQUAL( std::string("2011-05-21 11:43:22"), res );


		CPPUNIT_ASSERT( SQL("$1::date", boost::gregorian::date(3234, 1, 22) ) );
		CPPUNIT_ASSERT_EQUAL( std::string("3234-01-22"), res );


		CPPUNIT_ASSERT( SQL("$1::timestamp", boost::posix_time::ptime(boost::gregorian::date(2000, 1, 22), boost::posix_time::time_duration(12, 23, 4, 123400)) ) );
		CPPUNIT_ASSERT_EQUAL( std::string("2000-01-22 12:23:04.1234"), res );



		CPPUNIT_ASSERT( SQL("$1::interval", boost::gregorian::date_duration(65))  );
		CPPUNIT_ASSERT_EQUAL( std::string("2 month 5 day 00:00:00"), res );

		CPPUNIT_ASSERT( SQL("$1::interval", boost::posix_time::time_duration(23, 59, 59, 999999))  );
		CPPUNIT_ASSERT_EQUAL( std::string("0 month 0 day 23:59:59.999999"), res );


		utils::DateTimeDuration dtd(
			boost::gregorian::date_duration(65),
			boost::posix_time::time_duration(23, 51, 29, 999999));

		CPPUNIT_ASSERT( SQL("$1::interval", dtd)  );
		CPPUNIT_ASSERT_EQUAL( std::string("2 month 5 day 23:51:29.999999"), res );


		CPPUNIT_ASSERT( SQL("$1::varbit", std::bitset<8>(std::string("00010111")))  );
		CPPUNIT_ASSERT_EQUAL( std::string("11101000"), res );

		CPPUNIT_ASSERT( SQL("$1::varbit", std::bitset<16>(std::string("0001011100010111")))  );
		CPPUNIT_ASSERT_EQUAL( std::string("1110100011101000"), res );

		CPPUNIT_ASSERT( SQL("$1::varbit", std::bitset<32>(std::string("00010111000101110001011100010111")))  );
		CPPUNIT_ASSERT_EQUAL( std::string("11101000111010001110100011101000"), res );

		CPPUNIT_ASSERT( SQL("$1::varbit", std::bitset<64>(std::string("0001011100010111000101110001011100010111000101110001011100010111")))  );
		CPPUNIT_ASSERT_EQUAL( std::string("1110100011101000111010001110100011101000111010001110100011101000"), res );

		CPPUNIT_ASSERT( SQL("$1::varbit", std::bitset<128>(std::string("00010111000101110001011100010111000101110001011100010111000101110001011100010111000101110001011100010111000101110001011100010111")))  );
		CPPUNIT_ASSERT_EQUAL( std::string("11101000111010001110100011101000111010001110100011101000111010001110100011101000111010001110100011101000111010001110100011101000"), res );

		CPPUNIT_ASSERT( SQL("$1::varbit", std::bitset<256>(std::string("0001011100010111000101110001011100010111000101110001011100010111000101110001011100010111000101110001011100010111000101110001011100010111000101110001011100010111000101110001011100010111000101110001011100010111000101110001011100010111000101110001011100010111")))  );
		CPPUNIT_ASSERT_EQUAL( std::string("1110100011101000111010001110100011101000111010001110100011101000111010001110100011101000111010001110100011101000111010001110100011101000111010001110100011101000111010001110100011101000111010001110100011101000111010001110100011101000111010001110100011101000"), res );

		std::vector<unsigned char> vec;

		vec.resize(5);
		vec[0] = '1';
		vec[1] = '*';
		vec[2] = 'x';
		vec[3] = '&';
		vec[4] = '=';
		CPPUNIT_ASSERT( SQL("$1::bytea", vec) );
		CPPUNIT_ASSERT_EQUAL( std::string("1*x&="), res );

	}



	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////



};
CPPUNIT_TEST_SUITE_REGISTRATION( FromCpp2Db );


//////////////////////////////////////////////////////////////////////////

