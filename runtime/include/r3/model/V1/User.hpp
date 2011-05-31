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
		
			namespace tuple
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
				};
				typedef boost::shared_ptr<User> User_ptr;
				
			}
			
			class User
				: public CategoryBase<V1, User, tuple::User>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuple::User Tuple;
				typedef tuple::User_ptr Tuple_ptr;
				
				typedef V1 Schema;
				
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
				
			protected:
				std::string tupleFillKey(Tuple &tup);
				std::string tupleInsSql(Tuple &tup);
				std::string tupleUpdSql(Tuple &tup);
				std::string tupleSelSql(Tuple &tup);
				void tupleInsBind(Tuple &tup, pgc::Statement &stm);
				void tupleUpdBind(Tuple &tup, pgc::Statement &stm);
				
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
				: CategoryBase<V1, User, tuple::User>("User")
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
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void User::ins(User::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void User::upd(User::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void User::upd(User::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void User::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void User::del(User::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void User::del(User::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline User::Tuple_ptr  User::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline User::Tuple_ptr User::sel(User::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  User::tupleFillKey(Tuple &tup)
			{
				std::string res(3, '0');
				
				if(tup.attrInHasRights.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.login.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.password.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				return res;
			}
			inline std::string  User::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
				if(tup.attrInHasRights.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_attrInHasRights_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.login.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_login_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.password.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_password_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  User::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  User::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  User::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.attrInHasRights.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.attrInHasRights.value(), idx + 1);
					idx++;
				}
				
				if(tup.login.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.login.value(), idx + 1);
					idx++;
				}
				
				if(tup.password.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.password.value(), idx + 1);
					idx++;
				}
			}
			inline void  User::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
