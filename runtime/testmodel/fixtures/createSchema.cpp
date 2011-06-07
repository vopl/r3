#include "stdafx.h"
#include <cppunit/config/SourcePrefix.h>
#include <string>
#include "r3/data.hpp"


class CreateSchema
	: public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( CreateSchema );
	CPPUNIT_TEST( connected );

	CPPUNIT_TEST( _createDropSchema );

	CPPUNIT_TEST_SUITE_END();

protected:
	r3::Data _dat;

public:
	void setUp()
	{
		_dat.startInThread("dbname=test user=postgres password=postgres port=5432");
	}

	void tearDown()
	{
		_dat.stopInThread();
	}

protected:
	void connected()
	{
		CPPUNIT_ASSERT( pgc::ecs_ok == _dat.con().status());
	}
















	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	void _createDropSchema()
	{
		int cnt;
		CPPUNIT_ASSERT_NO_THROW(
			_dat.con().once("SELECT COUNT(*) FROM information_schema.schemata WHERE schema_name=$1").exec(std::string("Test_myId")).throwIfError().fetch(0,0,cnt)
		);
		if(cnt)
		{
			CPPUNIT_ASSERT_NO_THROW(
				_dat.con().once("DROP SCHEMA \"Test_myId\" CASCADE").exec().throwIfError()
			);
		}
		CPPUNIT_ASSERT_NO_THROW(_dat.getTest("myId")->dbCreate());
		CPPUNIT_ASSERT_NO_THROW(_dat.getTest("myId")->dbDrop());
	}


	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////



};
CPPUNIT_TEST_SUITE_REGISTRATION( CreateSchema );


//////////////////////////////////////////////////////////////////////////

