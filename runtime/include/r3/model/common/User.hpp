#ifndef _r3_model_common_User_hpp_
#define _r3_model_common_User_hpp_

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
			class HasRights;
			typedef boost::shared_ptr<HasRights> HasRights_ptr;
			
			class User
				: public CategoryBase<User>
			{
			
			public:
				static const bool isAbstract = false;
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Owner
					//HasRights
					o(this, _schema->getCategory<HasRights>().get(), (r3::fields::Bool *)NULL, "attrInHasRights");
					//User
					o(this, _schema->getCategory<User>().get(), (r3::fields::String *)NULL, "login");
					o(this, _schema->getCategory<User>().get(), (r3::fields::String *)NULL, "password");
				}
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				User(Schema *s)
					: CategoryBase<User>("User")
					, _schema(s)
				{
				}
				
				~User()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<User> User_ptr;
		}
	}
}

#endif
