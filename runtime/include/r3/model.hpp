// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_hpp_
#define _r3_model_hpp_

#include "r3/modelBase.hpp"

#include "r3/model/Undefined.hpp"
#include "r3/model/common.hpp"
#include "r3/model/common2.hpp"

namespace r3
{
	class Model
		: public ModelBase
	{
		typedef std::map<std::string, r3::model::Undefined_ptr> TMUndefined;
		TMUndefined _Undefined;
		typedef std::map<std::string, r3::model::common_ptr> TMcommon;
		TMcommon _common;
		typedef std::map<std::string, r3::model::common2_ptr> TMcommon2;
		TMcommon2 _common2;
		
	public:
		r3::model::Undefined_ptr getUndefined(const char *id)
		{
			return getSchemaImpl(_Undefined, id);
		}
		r3::model::common_ptr getcommon(const char *id)
		{
			return getSchemaImpl(_common, id);
		}
		r3::model::common2_ptr getcommon2(const char *id)
		{
			return getSchemaImpl(_common2, id);
		}
		
	};
	
}

#endif

