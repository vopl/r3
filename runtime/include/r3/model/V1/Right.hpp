// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_Right_hpp_
#define _r3_model_V1_Right_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class V1;
		typedef boost::shared_ptr<V1> V1_ptr;
		
		namespace s_V1
		{
		
			class Right
				: public CategoryBase<Right>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
				struct Domainvalue
				{
					static const size_t amount = 3;
					static const char *values[amount];
				};
				
				
			public:
				struct Tuple
						: public CategoryBase<Right>::Tuple
				{
					// Right
					r3::fields::String name;
					r3::fields::Enum<Right::Domainvalue> value;
					r3::relations::Relation2n<HasRights> rights;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Right();
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
				Right(V1 *s);
				
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
			typedef boost::shared_ptr<Right> Right_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Right::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Right::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Right
				Right *c_Right = _schema->getCategory<Right>().get();
				o(this, c_Right, (r3::fields::String *)&tup.name, "name");
				o(this, c_Right, (r3::fields::Enum<Right::Domainvalue>*)&tup.value, "value");
			}
			
			template <class Oper> void Right::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Right
				Right *c_Right = _schema->getCategory<Right>().get();
				o(this, c_Right, _schema->getCategory<HasRights>().get(), (r3::relations::Relation2n<HasRights>*)&tup.rights,	"rights",	(r3::relations::Relation2n<Right>*)NULL,	"owners",	rs_src);
			}
			
			template <class Oper> void Right::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Right
			}
			
			inline Right::Right(V1 *s)
				: CategoryBase<Right>("Right")
				, _schema(s)
			{
			}
			
			inline Right::~Right()
			{
			}
			
			inline V1 *Right::schema()
			{
				return _schema;
			}
			
			inline void Right::ins(Right::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Right::ins(Right::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Right::upd(Right::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Right::upd(Right::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Right::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Right::del(Right::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Right::del(Right::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Right::Tuple_ptr  Right::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Right::Tuple_ptr Right::sel(Right::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Right::tupleFillKey(Tuple &tup)
			{
				std::string res(2, '0');
				
				if(tup.name.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.value.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				return res;
			}
			inline std::string  Right::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
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
				
				if(tup.value.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_value_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  Right::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Right::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Right::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.name.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.name.value(), idx + 1);
					idx++;
				}
				
				if(tup.value.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.value.value(), idx + 1);
					idx++;
				}
			}
			inline void  Right::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
