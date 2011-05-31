// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_People_hpp_
#define _r3_model_Test_People_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			class People
				: public CategoryBase<People>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
				struct Domainsex
				{
					static const size_t amount = 0;
					static const char *values[amount];
				};
				
				
			public:
				struct Tuple
						: public CategoryBase<People>::Tuple
				{
					// People
					r3::fields::Date birth;
					r3::fields::String middlename;
					r3::fields::String name;
					r3::fields::Image photo;
					r3::fields::Enum<People::Domainsex> sex;
					r3::fields::String surname;
					r3::relations::Relation2n<Service> observableServices;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~People();
				Test *schema();
				
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
				People(Test *s);
				
			protected:
				Test *_schema;
				
			protected:
				std::string tupleFillKey(Tuple &tup);
				std::string tupleInsSql(Tuple &tup);
				std::string tupleUpdSql(Tuple &tup);
				std::string tupleSelSql(Tuple &tup);
				void tupleInsBind(Tuple &tup, pgc::Statement &stm);
				void tupleUpdBind(Tuple &tup, pgc::Statement &stm);
				
			};
			typedef boost::shared_ptr<People> People_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void People::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void People::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, (r3::fields::Date *)&tup.birth, "birth");
				o(this, c_People, (r3::fields::String *)&tup.middlename, "middlename");
				o(this, c_People, (r3::fields::String *)&tup.name, "name");
				o(this, c_People, (r3::fields::Image *)&tup.photo, "photo");
				o(this, c_People, (r3::fields::Enum<People::Domainsex>*)&tup.sex, "sex");
				o(this, c_People, (r3::fields::String *)&tup.surname, "surname");
			}
			
			template <class Oper> void People::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.observableServices,	"observableServices",	(r3::relations::Relation2n<People>*)NULL,	"observers",	rs_dst);
			}
			
			template <class Oper> void People::enumIndicesFromBasesAndSelf(Oper o)
			{
				//People
			}
			
			inline People::People(Test *s)
				: CategoryBase<People>("People")
				, _schema(s)
			{
			}
			
			inline People::~People()
			{
			}
			
			inline Test *People::schema()
			{
				return _schema;
			}
			
			inline void People::ins(People::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void People::ins(People::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void People::upd(People::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void People::upd(People::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void People::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void People::del(People::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void People::del(People::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline People::Tuple_ptr  People::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline People::Tuple_ptr People::sel(People::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  People::tupleFillKey(Tuple &tup)
			{
				std::string res(6, '0');
				
				if(tup.birth.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.middlename.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.name.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.photo.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				if(tup.sex.fvs() != fields::fvs_notset) {
					res[4] = '1';
				}
				
				if(tup.surname.fvs() != fields::fvs_notset) {
					res[5] = '1';
				}
				
				return res;
			}
			inline std::string  People::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
				if(tup.birth.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_birth_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.middlename.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_middlename_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.name.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_name_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.photo.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_photo_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.sex.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_sex_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.surname.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_surname_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  People::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  People::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  People::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.birth.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.birth.value(), idx + 1);
					idx++;
				}
				
				if(tup.middlename.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.middlename.value(), idx + 1);
					idx++;
				}
				
				if(tup.name.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.name.value(), idx + 1);
					idx++;
				}
				
				if(tup.photo.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.photo.value(), idx + 1);
					idx++;
				}
				
				if(tup.sex.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.sex.value(), idx + 1);
					idx++;
				}
				
				if(tup.surname.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.surname.value(), idx + 1);
					idx++;
				}
			}
			inline void  People::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
