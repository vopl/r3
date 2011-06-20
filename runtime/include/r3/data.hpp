// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_data_hpp_
#define _r3_data_hpp_

#include "r3/dataBase.hpp"

// инклюды классов схем
#include "r3/data/Test.hpp"
#include "r3/data/V1.hpp"

namespace r3
{
	// вся дата
	class Data
		: public DataBase
	{
		// тип карты id -> schema ptr
		typedef std::map<std::string, r3::data::Test_ptr> TMTest;
		TMTest _Test;
		typedef std::map<std::string, r3::data::V1_ptr> TMV1;
		TMV1 _V1;
		
	public:
		// геттеры для схем
		r3::data::Test_ptr getTest(const char *id)
		{
			return getSchemaImpl(_Test, id);
		}
		r3::data::V1_ptr getV1(const char *id)
		{
			return getSchemaImpl(_V1, id);
		}
		
	};
	
}

#endif

