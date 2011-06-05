// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_hpp_
#define _r3_model_hpp_

#include "r3/modelBase.hpp"

#include "r3/model/Test.hpp"
#include "r3/model/V1.hpp"

namespace r3
{
	class Model
		: public ModelBase
	{
		typedef std::map<std::string, r3::model::Test_ptr> TMTest;
		TMTest _Test;
		typedef std::map<std::string, r3::model::V1_ptr> TMV1;
		TMV1 _V1;
		
	public:
		r3::model::Test_ptr getTest(const char *id)
		{
			return getSchemaImpl(_Test, id);
		}
		r3::model::V1_ptr getV1(const char *id)
		{
			return getSchemaImpl(_V1, id);
		}
		
	};
	
}

#endif

