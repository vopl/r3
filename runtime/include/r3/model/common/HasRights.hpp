#ifndef _r3_model_common_HasRights_hpp_
#define _r3_model_common_HasRights_hpp_

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
			class Category1;
			typedef boost::shared_ptr<Category1> Category1_ptr;
			
			//deriveds
			class User;
			typedef boost::shared_ptr<User> User_ptr;
			class Role;
			typedef boost::shared_ptr<Role> Role_ptr;
			
			class HasRights
				: public CategoryBase<HasRights>
			{
			
			public:
				typedef bmpl::vector <
				Category1
				> TVBases;
				
				typedef bmpl::vector <
				User
				, Role
				> TVDeriveds;
				
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
				Schema *_schema;
				
			public:
				HasRights(Schema *s)
					: CategoryBase<HasRights>("HasRights")
					, _schema(s)
				{
				}
				
				~HasRights()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<HasRights> HasRights_ptr;
		}
	}
}

#endif
