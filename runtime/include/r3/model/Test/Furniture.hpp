// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Furniture_hpp_
#define _r3_model_Test_Furniture_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/Test/Stock.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			namespace tuple
			{
				struct DomainFurnitureconstraints
				{
					static const size_t amount = 4;
					static const char *values[amount];
				};
				
				struct Furniture
						: public TupleBase<Furniture>
				{
					// Furniture
					r3::fields::Set<DomainFurnitureconstraints> constraints;
					r3::fields::Int16 depth;
					r3::fields::Int16 height;
					r3::fields::Real32 weight;
					r3::fields::Int16 width;
					// Stock
					r3::fields::Money cost;
					r3::fields::Date incomingDate;
					r3::fields::String inventoryNumber;
					r3::fields::Enum<DomainStocksecurityStatus> securityStatus;
					r3::relations::Relation2n<Service> services;
				};
				typedef boost::shared_ptr<Furniture> Furniture_ptr;
				
			}
			
			class Furniture
				: public CategoryBase<Test, Furniture, tuple::Furniture>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuple::Furniture Tuple;
				typedef tuple::Furniture_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Furniture();
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
				Furniture(Test *s);
				
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
			typedef boost::shared_ptr<Furniture> Furniture_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Furniture::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Stock>().get());
			}
			
			template <class Oper> void Furniture::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Furniture
				Furniture *c_Furniture = _schema->getCategory<Furniture>().get();
				o(this, c_Furniture, (r3::fields::Set<tuple::DomainFurnitureconstraints>*)&tup.constraints, "constraints");
				o(this, c_Furniture, (r3::fields::Int16 *)&tup.depth, "depth");
				o(this, c_Furniture, (r3::fields::Int16 *)&tup.height, "height");
				o(this, c_Furniture, (r3::fields::Real32 *)&tup.weight, "weight");
				o(this, c_Furniture, (r3::fields::Int16 *)&tup.width, "width");
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_Stock, (r3::fields::Date *)&tup.incomingDate, "incomingDate");
				o(this, c_Stock, (r3::fields::String *)&tup.inventoryNumber, "inventoryNumber");
				o(this, c_Stock, (r3::fields::Enum<tuple::DomainStocksecurityStatus>*)&tup.securityStatus, "securityStatus");
			}
			
			template <class Oper> void Furniture::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Furniture
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2n<Stock>*)NULL,	"stocks",	rs_dst);
			}
			
			template <class Oper> void Furniture::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Furniture
				//Stock
			}
			
			inline Furniture::Furniture(Test *s)
				: CategoryBase<Test, Furniture, tuple::Furniture>("Furniture")
				, _schema(s)
			{
			}
			
			inline Furniture::~Furniture()
			{
			}
			
			inline Test *Furniture::schema()
			{
				return _schema;
			}
			
			inline void Furniture::ins(Furniture::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Furniture::ins(Furniture::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Furniture::upd(Furniture::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Furniture::upd(Furniture::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Furniture::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Furniture::del(Furniture::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Furniture::del(Furniture::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Furniture::Tuple_ptr  Furniture::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Furniture::Tuple_ptr Furniture::sel(Furniture::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Furniture::tupleFillKey(Tuple &tup)
			{
				std::string res(9, '0');
				
				if(tup.constraints.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.cost.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.depth.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.height.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				if(tup.incomingDate.fvs() != fields::fvs_notset) {
					res[4] = '1';
				}
				
				if(tup.inventoryNumber.fvs() != fields::fvs_notset) {
					res[5] = '1';
				}
				
				if(tup.securityStatus.fvs() != fields::fvs_notset) {
					res[6] = '1';
				}
				
				if(tup.weight.fvs() != fields::fvs_notset) {
					res[7] = '1';
				}
				
				if(tup.width.fvs() != fields::fvs_notset) {
					res[8] = '1';
				}
				
				return res;
			}
			inline std::string  Furniture::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
				if(tup.constraints.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_constraints_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.cost.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_cost_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.depth.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_depth_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.height.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_height_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.incomingDate.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_incomingDate_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.inventoryNumber.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_inventoryNumber_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.securityStatus.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_securityStatus_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.weight.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_weight_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.width.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_width_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  Furniture::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Furniture::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Furniture::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.constraints.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.constraints.value(), idx + 1);
					idx++;
				}
				
				if(tup.cost.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.cost.value(), idx + 1);
					idx++;
				}
				
				if(tup.depth.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.depth.value(), idx + 1);
					idx++;
				}
				
				if(tup.height.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.height.value(), idx + 1);
					idx++;
				}
				
				if(tup.incomingDate.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.incomingDate.value(), idx + 1);
					idx++;
				}
				
				if(tup.inventoryNumber.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.inventoryNumber.value(), idx + 1);
					idx++;
				}
				
				if(tup.securityStatus.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.securityStatus.value(), idx + 1);
					idx++;
				}
				
				if(tup.weight.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.weight.value(), idx + 1);
					idx++;
				}
				
				if(tup.width.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.width.value(), idx + 1);
					idx++;
				}
			}
			inline void  Furniture::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
