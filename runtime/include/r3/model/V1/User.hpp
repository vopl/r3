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
		
			namespace tuples
			{
				struct User
						: public TupleBase<User>
				{
					// HasRights
					r3::fields::Bool attrInHasRights;
					r3::relations::Relation2n<Right> owners;
					// Owner
					r3::relations::Relation2n<Department> childs;
					// User
					r3::fields::String login;
					r3::fields::String password;
					r3::relations::Relation2n<Role> users;
					
					static const size_t _fieldsAmount = 3;
					static const size_t _relationsAmount = 3;
					
				};
				typedef boost::shared_ptr<User> User_ptr;
				
			}
			
			class User
				: public CategoryBase<V1, User, tuples::User>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::User Tuple;
				typedef tuples::User_ptr Tuple_ptr;
				
				typedef V1 Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~User();
				V1 *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				User(V1 *s);
				
			protected:
				V1 *_schema;
				
			};
			typedef boost::shared_ptr<User> User_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void User::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<HasRights>().get());
				o(this, schema()->getCategory<Owner>().get());
			}
			
			template <class Oper> void User::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, &tup.attrInHasRights, "attrInHasRights");
				//Owner
				//User
				User *c_User = _schema->getCategory<User>().get();
				o(this, c_User, &tup.login, "login");
				o(this, c_User, &tup.password, "password");
			}
			
			template <class Oper> void User::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, _schema->getCategory<Right>().get(), (r3::relations::Relation2n<Right>*)&tup.owners,	"owners",	(r3::relations::Relation2n<HasRights>*)NULL,	"rights",	rs_dst);
				//Owner
				Owner *c_Owner = _schema->getCategory<Owner>().get();
				o(this, c_Owner, _schema->getCategory<Department>().get(), (r3::relations::Relation2n<Department>*)&tup.childs,	"childs",	(r3::relations::Relation2one<Owner>*)NULL,	"parent",	rs_dst);
				//User
				User *c_User = _schema->getCategory<User>().get();
				o(this, c_User, _schema->getCategory<Role>().get(), (r3::relations::Relation2n<Role>*)&tup.users,	"users",	(r3::relations::Relation2n<User>*)NULL,	"roles",	rs_dst);
			}
			
			template <class Oper> void User::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//HasRights
				//Owner
				//User
			}
			
			inline User::User(V1 *s)
				: CategoryBase<V1, User, tuples::User>("User")
				, _schema(s)
			{
			}
			
			inline User::~User()
			{
			}
			
			inline V1 *User::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
