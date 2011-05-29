// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_User_hpp_
#define _r3_model_V1_User_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/V1/HasRights.hpp"
#include "r3/model/V1/Owner.hpp"

namespace r3
{
	namespace model
	{
	
		class V1;
		typedef boost::shared_ptr<V1> V1_ptr;
		
		namespace s_V1
		{
		
			class User
				: public CategoryBase<User>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<HasRights>().get());
					o(this, schema()->getCategory<Owner>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					o(this, c_HasRights, (r3::fields::Bool *)NULL, "attrInHasRights");
					//Owner
					//User
					User *c_User = _schema->getCategory<User>().get();
					o(this, c_User, (r3::fields::String *)NULL, "login");
					o(this, c_User, (r3::fields::String *)NULL, "password");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					o(this, c_HasRights, _schema->getCategory<Right>().get(), (r3::relations::Relation2n *)NULL,	"owners",	(r3::relations::Relation2n *)NULL,	"rights",	rs_dst);
					//Owner
					Owner *c_Owner = _schema->getCategory<Owner>().get();
					o(this, c_Owner, _schema->getCategory<Department>().get(), (r3::relations::Relation2n *)NULL,	"childs",	(r3::relations::Relation2one *)NULL,	"parent",	rs_dst);
					//User
					User *c_User = _schema->getCategory<User>().get();
					o(this, c_User, _schema->getCategory<Role>().get(), (r3::relations::Relation2n *)NULL,	"users",	(r3::relations::Relation2n *)NULL,	"roles",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//HasRights
					//Owner
					//User
				}
				
			public:
				typedef V1 Schema;
				typedef boost::shared_ptr<V1> Schema_ptr;
				typedef boost::weak_ptr<V1> Schema_wtr;
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
