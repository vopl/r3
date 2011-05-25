#ifndef _r3_model_common_Department_hpp_
#define _r3_model_common_Department_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		namespace s_common
		{
		
			//bases
			class Owner;
			typedef boost::shared_ptr<Owner> Owner_ptr;
			
			class Department
				: public CategoryBase<Department>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
				Schema *_schema;
				
			public:
				Department(Schema *s)
					: CategoryBase<Department>("Department")
					, _schema(s)
				{
				}
				
				~Department()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Department> Department_ptr;
		}
	}
}

#endif
