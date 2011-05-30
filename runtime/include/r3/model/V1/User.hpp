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
				
			public:
			
			public:
				struct Tuple
						: public HasRights::Tuple
						, public Owner::Tuple
				{
					r3::fields::String login;
					r3::fields::String password;
					r3::relations::Relation2n<Role> users;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~User();
				V1 *schema();
				
				void ins(Tuple &tup);
				void ins(Tuple_ptr tup);
				
				void upd(Tuple &tup);
				void upd(Tuple_ptr tup);
				
				void del(const fields::Id &id);
				void del(Tuple &tup);
				void del(Tuple_ptr tup);
				
				Tuple_ptr sel(const fields::Id &id);
				Tuple_ptr sel(Tuple_ptr tup);
				
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
			
			template <class Oper> void User::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, (r3::fields::Bool *)&tup.attrInHasRights, "attrInHasRights");
				//Owner
				//User
				User *c_User = _schema->getCategory<User>().get();
				o(this, c_User, (r3::fields::String *)&tup.login, "login");
				o(this, c_User, (r3::fields::String *)&tup.password, "password");
			}
			
			template <class Oper> void User::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
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
			
			template <class Oper> void User::enumIndicesFromBasesAndSelf(Oper o)
			{
				//HasRights
				//Owner
				//User
			}
			
			inline User::User(V1 *s)
				: CategoryBase<User>("User")
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
			
			inline void User::ins(User::Tuple &tup)
			{
				return CategoryBase<User>::ins(this, tup);
			}
			
			inline void User::ins(User::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void User::upd(User::Tuple &tup)
			{
				return CategoryBase<User>::upd(this, tup);
			}
			
			inline void User::upd(User::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void User::del(const fields::Id &id)
			{
				return CategoryBase<User>::del(this, id);
			}
			
			inline void User::del(User::Tuple &tup)
			{
				return CategoryBase<User>::del(this, tup);
			}
			
			inline void User::del(User::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline User::Tuple_ptr  User::sel(const fields::Id &id)
			{
				return CategoryBase<User>::sel(this, id);
			}
			
			inline User::Tuple_ptr User::sel(User::Tuple_ptr tup)
			{
				return CategoryBase<User>::sel(this, tup);
			}
			
		}
	}
}

#endif
