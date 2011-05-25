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
				typedef bmpl::vector <
				> TVBases;
				
				typedef bmpl::vector <
				> TVDeriveds;
				
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
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
