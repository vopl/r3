#ifndef _r3_model_common_Right_hpp_
#define _r3_model_common_Right_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		namespace s_common
		{
		
			class Right
				: public CategoryBase<Right>
			{
			
			public:
				static const bool isAbstract = false;
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Right
					o(this, _schema->getCategory<Right>().get(), (r3::fields::String *)NULL, "name");
					o(this, _schema->getCategory<Right>().get(), (r3::fields::Enum *)NULL, "value");
				}
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Right(Schema *s)
					: CategoryBase<Right>("Right")
					, _schema(s)
				{
				}
				
				~Right()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Right> Right_ptr;
		}
	}
}

#endif
