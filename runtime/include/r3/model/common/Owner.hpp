#ifndef _r3_model_common_Owner_hpp_
#define _r3_model_common_Owner_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		namespace s_common
		{
		
			//deriveds
			class Department;
			typedef boost::shared_ptr<Department> Department_ptr;
			class User;
			typedef boost::shared_ptr<User> User_ptr;
			
			class Owner
				: public CategoryBase<Owner>
			{
			
			public:
				static const bool isAbstract = true;
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Owner
					Owner *c_Owner = _schema->getCategory<Owner>().get();
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Owner
					Owner *c_Owner = _schema->getCategory<Owner>().get();
				}
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Owner(Schema *s)
					: CategoryBase<Owner>("Owner")
					, _schema(s)
				{
				}
				
				~Owner()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Owner> Owner_ptr;
		}
	}
}

#endif
