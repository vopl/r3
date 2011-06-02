// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_hpp_
#define _r3_model_hpp_

#include "r3/modelBase.hpp"

#include "r3/model/Test.hpp"

namespace r3
{
	class Model
		: public ModelBase
	{
		typedef std::map<std::string, r3::model::Test_ptr> TMTest;
		TMTest _Test;
		
	public:
		r3::model::Test_ptr getTest(const char *id)
		{
			return getSchemaImpl(_Test, id);
		}
		
	};
	
}

#endif

