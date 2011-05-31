// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Stock_hpp_
#define _r3_model_Test_Stock_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			class Stock
				: public CategoryBase<Stock>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
				struct DomainsecurityStatus
				{
					static const size_t amount = 3;
					static const char *values[amount];
				};
				
				
			public:
				struct Tuple
						: public CategoryBase<Stock>::Tuple
				{
					// Stock
					r3::fields::Money cost;
					r3::fields::Date incomingDate;
					r3::fields::String inventoryNumber;
					r3::fields::Enum<Stock::DomainsecurityStatus> securityStatus;
					r3::relations::Relation2n<Service> services;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Stock();
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
				Stock(Test *s);
				
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
			typedef boost::shared_ptr<Stock> Stock_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Stock::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Stock::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_Stock, (r3::fields::Date *)&tup.incomingDate, "incomingDate");
				o(this, c_Stock, (r3::fields::String *)&tup.inventoryNumber, "inventoryNumber");
				o(this, c_Stock, (r3::fields::Enum<Stock::DomainsecurityStatus>*)&tup.securityStatus, "securityStatus");
			}
			
			template <class Oper> void Stock::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2n<Stock>*)NULL,	"stocks",	rs_dst);
			}
			
			template <class Oper> void Stock::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Stock
			}
			
			inline Stock::Stock(Test *s)
				: CategoryBase<Stock>("Stock")
				, _schema(s)
			{
			}
			
			inline Stock::~Stock()
			{
			}
			
			inline Test *Stock::schema()
			{
				return _schema;
			}
			
			inline void Stock::ins(Stock::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Stock::ins(Stock::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Stock::upd(Stock::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Stock::upd(Stock::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Stock::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Stock::del(Stock::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Stock::del(Stock::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Stock::Tuple_ptr  Stock::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Stock::Tuple_ptr Stock::sel(Stock::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Stock::tupleFillKey(Tuple &tup)
			{
				std::string res(4, '0');
				
				if(tup.cost.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.incomingDate.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.inventoryNumber.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.securityStatus.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				return res;
			}
			inline std::string  Stock::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
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
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  Stock::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Stock::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Stock::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.cost.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.cost.value(), idx + 1);
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
			}
			inline void  Stock::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
