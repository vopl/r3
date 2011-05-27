#ifndef _r3_model_common_User_hpp_
#define _r3_model_common_User_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/common/Category1.hpp"
#include "r3/model/common/Owner.hpp"
#include "r3/model/common/HasRights.hpp"

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
					//Category1
					//Owner
					//HasRights
					//User
					User *c_User = _schema->getCategory<User>().get();
					o(this, c_User, (r3::fields::String *)NULL, "login");
					o(this, c_User, (r3::fields::String *)NULL, "password");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Category1
					//Owner
					Owner *c_Owner = _schema->getCategory<Owner>().get();
					o(this, c_Owner, (r3::relations::Relation2n *)NULL,	"childs",	(r3::relations::Relation2one *)NULL,	"parent",	rs_dst);
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					o(this, c_HasRights, (r3::relations::Relation2n *)NULL,	"owners",	(r3::relations::Relation2n *)NULL,	"rights",	rs_dst);
					//User
					User *c_User = _schema->getCategory<User>().get();
					o(this, c_User, (r3::relations::Relation2n *)NULL,	"users",	(r3::relations::Relation2n *)NULL,	"roles",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Category1
					//Owner
					//HasRights
					//User
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
