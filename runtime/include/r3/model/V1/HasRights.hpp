// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_HasRights_hpp_
#define _r3_model_V1_HasRights_hpp_

#include "r3/categoryBase.hpp"

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
				struct HasRights
						: public TupleBase<HasRights>
				{
					// HasRights
					r3::fields::Bool attrInHasRights;
					r3::relations::Relation2n<Right> owners;
				};
				typedef boost::shared_ptr<HasRights> HasRights_ptr;
				
			}
			
			class HasRights
				: public CategoryBase<V1, HasRights, tuple::HasRights>
			{
			
			public:
				static const bool isAbstract = true;
				
				typedef tuple::HasRights Tuple;
				typedef tuple::HasRights_ptr Tuple_ptr;
				
				typedef V1 Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~HasRights();
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
				HasRights(V1 *s);
				
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
			typedef boost::shared_ptr<HasRights> HasRights_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void HasRights::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void HasRights::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, (r3::fields::Bool *)&tup.attrInHasRights, "attrInHasRights");
			}
			
			template <class Oper> void HasRights::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, _schema->getCategory<Right>().get(), (r3::relations::Relation2n<Right>*)&tup.owners,	"owners",	(r3::relations::Relation2n<HasRights>*)NULL,	"rights",	rs_dst);
			}
			
			template <class Oper> void HasRights::enumIndicesFromBasesAndSelf(Oper o)
			{
				//HasRights
			}
			
			inline HasRights::HasRights(V1 *s)
				: CategoryBase<V1, HasRights, tuple::HasRights>("HasRights")
				, _schema(s)
			{
			}
			
			inline HasRights::~HasRights()
			{
			}
			
			inline V1 *HasRights::schema()
			{
				return _schema;
			}
			
			inline void HasRights::ins(HasRights::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void HasRights::ins(HasRights::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void HasRights::upd(HasRights::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void HasRights::upd(HasRights::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void HasRights::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void HasRights::del(HasRights::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void HasRights::del(HasRights::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline HasRights::Tuple_ptr  HasRights::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline HasRights::Tuple_ptr HasRights::sel(HasRights::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  HasRights::tupleFillKey(Tuple &tup)
			{
				std::string res(1, '0');
				
				if(tup.attrInHasRights.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				return res;
			}
			inline std::string  HasRights::tupleInsSql(Tuple &tup)
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
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  HasRights::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  HasRights::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  HasRights::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.attrInHasRights.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.attrInHasRights.value(), idx + 1);
					idx++;
				}
			}
			inline void  HasRights::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
