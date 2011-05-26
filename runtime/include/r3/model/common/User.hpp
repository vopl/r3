#ifndef _r3_model_common_User_hpp_
#define _r3_model_common_User_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/common/HasRights.hpp"
#include "r3/model/common/Owner.hpp"

namespace r3
{
	namespace model
	{
	
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		namespace s_common
		{
		
			class User
				: public CategoryBase<User>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					o(this, c_HasRights, (r3::fields::Bool *)NULL, "attrInHasRights");
					//Owner
					Owner *c_Owner = _schema->getCategory<Owner>().get();
					//User
					User *c_User = _schema->getCategory<User>().get();
					o(this, c_User, (r3::fields::String *)NULL, "password");
					o(this, c_User, (r3::fields::String *)NULL, "login");
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					//Owner
					Owner *c_Owner = _schema->getCategory<Owner>().get();
					//User
					User *c_User = _schema->getCategory<User>().get();
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
