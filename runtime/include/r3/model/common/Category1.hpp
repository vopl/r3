#ifndef _r3_model_common_Category1_hpp_
#define _r3_model_common_Category1_hpp_

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
			class HasRights;
			typedef boost::shared_ptr<HasRights> HasRights_ptr;
			class User;
			typedef boost::shared_ptr<User> User_ptr;
			class Role;
			typedef boost::shared_ptr<Role> Role_ptr;
			
			class Category1
				: public CategoryBase<Category1>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Category1
					Category1 *c_Category1 = _schema->getCategory<Category1>().get();
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Category1
					Category1 *c_Category1 = _schema->getCategory<Category1>().get();
				}
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Category1(Schema *s)
					: CategoryBase<Category1>("Category1")
					, _schema(s)
				{
				}
				
				~Category1()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Category1> Category1_ptr;
		}
	}
}

#endif
