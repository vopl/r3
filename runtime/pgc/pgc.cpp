// pgc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

#include "connection.hpp"
#include "exception.hpp"
#include <boost/cstdint.hpp>


void createTestTable(pgc::Connection con)
{
	//////////////////////////////////////////////////////////////////////////
	con.once().sql("DROP TYPE mood CASCADE").exec();
	con.once().sql("DROP TABLE pgc_test CASCADE").exec();

	con.once().sql("CREATE TYPE mood AS ENUM ('sad', 'ok', 'happy')").exec().throwIfError();

	con.once().sql(
		"CREATE TABLE pgc_test("
		"	id SERIAL NOT NULL,"

		// smallint 2 bytes small-range integer -32768 to +32767 
		"	_smallint smallint,"
		// integer 4 bytes usual choice for integer -2147483648 to +2147483647 
		"	_integer integer,"
		// bigint 8 bytes large-range integer -9223372036854775808 to 9223372036854775807 
		"	_bigint bigint,"
		// decimal variable user-specified precision, exact no limit 
		"	_decimal decimal(11,6),"
		// numeric variable user-specified precision, exact no limit 
		"	_numeric numeric(10,7),"
		// real 4 bytes variable-precision, inexact 6 decimal digits precision 
		"	_real real,"
		// double precision 8 bytes variable-precision, inexact 15 decimal digits precision 
		"	_double double precision,"
		// money 8 bytes currency amount -92233720368547758.08 to +92233720368547758.07 
		"	_money money,"
		// character varying(n), varchar(n)  variable-length with limit 
		"	_varchar varchar,"
		// character(n), char(n)  fixed-length, blank padded 
		"	_char char(10),"
		// text variable unlimited length 
		"	_text text,"
		// bytea 1 or 4 bytes plus the actual binary string variable-length binary string 
		"	_bytea bytea,"
		// timestamp [ (p) ] [ without time zone ] 8 bytes both date and time 4713 BC 5874897 AD 1 microsecond / 14 digits 
		"	_timestamp timestamp,"
		// timestamp [ (p) ] with time zone 8 bytes both date and time, with time zone 4713 BC 5874897 AD 1 microsecond / 14 digits 
		"	_timestamptz timestamp with time zone,"
		// interval [ (p) ] 12 bytes time intervals -178000000 years 178000000 years 1 microsecond / 14 digits 
		"	_interval interval,"
		// date 4 bytes dates only 4713 BC 5874897 AD 1 day 
		"	_date date,"
		// time [ (p) ] [ without time zone ] 8 bytes times of day only 00:00:00 24:00:00 1 microsecond / 14 digits 
		"	_time time,"
		// time [ (p) ] with time zone 12 bytes times of day only, with time zone 00:00:00+1459 24:00:00-1459 1 microsecond / 14 digits 
		"	_timetz time with time zone,"
		// boolean can have one of only two states: “true” or “false”. 
		"	_boolean boolean,"
		// enum mood
		"	_mood mood,"
		// There are two SQL bit types: bit(n) and 
		"	_bit bit(10),"
		// bit varying(n), where n is a positive integer
		"	_varbit varbit,"
		// oid
		"	_oid oid,"


		"	CONSTRAINT pgc_test_pkey PRIMARY KEY (id)"
		");").exec().throwIfError();


	con.once().sql(
		"INSERT INTO pgc_test("
		"_smallint,_integer,_bigint,_numeric, _decimal, _real, _double, _money, _varchar, _char, _text, _bytea, _timestamp, _timestamptz, _interval, _date, _time, _timetz, _boolean, _mood, _bit, _varbit, _oid"
		")VALUES("
		"1,2,3,12.23445,55654.69,3.123,4.123,'1000,32'::money,'varchar text','char txt','text text',E'\\17601234\\010','2010-04-08 01:02:03','2010-01-15 23:23:32','1 12:59:10','2010-01-15','23:23:32','23:23:32',true,'ok',B'1010101010',B'10101',220"
		")").exec().throwIfError();
}

//////////////////////////////////////////////////////////////////////////
void selectTestTable(pgc::Connection con)
{
	pgc::Result res = con.once().sql("SELECT "
		"_smallint,_integer,_bigint,_numeric, _decimal, _real, _double, _money, _varchar, _char, _text, _bytea, _timestamp, _timestamptz, _interval, _date, _time, _timetz, _boolean, _mood, _bit, _varbit, _oid"
		" FROM pgc_test").exec().throwIfError();

	{
		char buf[4096];
		char *			v_pchar = buf;

		res.fetch(0, "_smallint", v_pchar);
		res.fetch(0, "_integer", v_pchar);
		res.fetch(0, "_bigint", v_pchar);
		res.fetch(0, "_numeric", v_pchar);
		res.fetch(0, "_decimal", v_pchar);
		res.fetch(0, "_real", v_pchar);
		res.fetch(0, "_double", v_pchar);
		res.fetch(0, "_money", v_pchar);
		res.fetch(0, "_varchar", v_pchar);
		res.fetch(0, "_char", v_pchar);
		res.fetch(0, "_text", v_pchar);
		res.fetch(0, "_bytea", v_pchar);
		res.fetch(0, "_timestamp", v_pchar);
		res.fetch(0, "_timestamptz", v_pchar);
		res.fetch(0, "_interval", v_pchar);
		res.fetch(0, "_date", v_pchar);
		res.fetch(0, "_time", v_pchar);
		res.fetch(0, "_timetz", v_pchar);
		res.fetch(0, "_boolean", v_pchar);
		res.fetch(0, "_mood", v_pchar);
		res.fetch(0, "_bit", v_pchar);
		res.fetch(0, "_varbit", v_pchar);
		res.fetch(0, "_oid", v_pchar);
	}


	std::string		v_stdstring;
	bool			v_bool;
	boost::int8_t	v_int8;
	boost::int16_t	v_int16;
	boost::int32_t	v_int32;
	boost::int64_t	v_int64;
	boost::uint8_t	v_uint8;
	boost::uint16_t	v_uint16;
	boost::uint32_t	v_uint32;
	boost::uint64_t	v_uint64;
	std::tm			v_stdtm;

// 	res.fetch(0, "_smallint", v_stdstring);
// 	res.fetch(0, "_smallint", v_bool);
// 	res.fetch(0, "_smallint", v_int8);
// 	res.fetch(0, "_smallint", v_int16);
// 	res.fetch(0, "_smallint", v_int32);
// 	res.fetch(0, "_smallint", v_int64);
// 	res.fetch(0, "_smallint", v_uint8);
// 	res.fetch(0, "_smallint", v_uint16);
// 	res.fetch(0, "_smallint", v_uint32);
// 	res.fetch(0, "_smallint", v_uint64);
// 	res.fetch(0, "_smallint", v_stdtm);
}

int _tmain(int argc, _TCHAR* argv[])
{
	pgc::Connection con;
	con.open("dbname=test user=postgres password=postgres port=5433");


	std::string str;

	try
	{
		createTestTable(con);
		selectTestTable(con);

// 		int i;
// 		con.once().sql("SELECT $1::varchar")
// 			.bind(i)
// 			.bind(220)
// 			.bind(std::string("sdfgsd"))
// 			.bind(str)
// 			.exec().fetch(str);
// 		;

		pgc::Result res = con.once().sql("SELECT '$1'::varchar").exec().throwIfError();

		for(size_t row(0); row<res.rows(); row++)
		{
			char *tmp = "init";
			res.fetch(row, (size_t)0, tmp);
		}
		
		;
	}
	catch (pgc::Exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}

	con.close();

	return 0;
}

