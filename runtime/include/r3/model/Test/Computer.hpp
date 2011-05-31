// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Computer_hpp_
#define _r3_model_Test_Computer_hpp_

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
		
			class Computer
				: public CategoryBase<Computer>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public CategoryBase<Computer>::Tuple
				{
					// Computer
					r3::fields::DateTimeInterval equipmentInterval;
					r3::fields::Timestamp equipmentStamp;
					r3::fields::Bool mobile;
					r3::fields::String model;
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
				~Computer();
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
				Computer(Test *s);
				
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
			typedef boost::shared_ptr<Computer> Computer_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Computer::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Stock>().get());
			}
			
			template <class Oper> void Computer::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Computer
				Computer *c_Computer = _schema->getCategory<Computer>().get();
				o(this, c_Computer, (r3::fields::DateTimeInterval *)&tup.equipmentInterval, "equipmentInterval");
				o(this, c_Computer, (r3::fields::Timestamp *)&tup.equipmentStamp, "equipmentStamp");
				o(this, c_Computer, (r3::fields::Bool *)&tup.mobile, "mobile");
				o(this, c_Computer, (r3::fields::String *)&tup.model, "model");
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_Stock, (r3::fields::Date *)&tup.incomingDate, "incomingDate");
				o(this, c_Stock, (r3::fields::String *)&tup.inventoryNumber, "inventoryNumber");
				o(this, c_Stock, (r3::fields::Enum<Stock::DomainsecurityStatus>*)&tup.securityStatus, "securityStatus");
			}
			
			template <class Oper> void Computer::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Computer
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2n<Stock>*)NULL,	"stocks",	rs_dst);
			}
			
			template <class Oper> void Computer::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Computer
				//Stock
			}
			
			inline Computer::Computer(Test *s)
				: CategoryBase<Computer>("Computer")
				, _schema(s)
			{
			}
			
			inline Computer::~Computer()
			{
			}
			
			inline Test *Computer::schema()
			{
				return _schema;
			}
			
			inline void Computer::ins(Computer::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Computer::ins(Computer::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Computer::upd(Computer::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Computer::upd(Computer::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Computer::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Computer::del(Computer::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Computer::del(Computer::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Computer::Tuple_ptr  Computer::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Computer::Tuple_ptr Computer::sel(Computer::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Computer::tupleFillKey(Tuple &tup)
			{
				std::string res(8, '0');
				
				if(tup.cost.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.equipmentInterval.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.equipmentStamp.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.incomingDate.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				if(tup.inventoryNumber.fvs() != fields::fvs_notset) {
					res[4] = '1';
				}
				
				if(tup.mobile.fvs() != fields::fvs_notset) {
					res[5] = '1';
				}
				
				if(tup.model.fvs() != fields::fvs_notset) {
					res[6] = '1';
				}
				
				if(tup.securityStatus.fvs() != fields::fvs_notset) {
					res[7] = '1';
				}
				
				return res;
			}
			inline std::string  Computer::tupleInsSql(Tuple &tup)
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
				
				if(tup.equipmentInterval.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_equipmentInterval_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.equipmentStamp.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_equipmentStamp_\"";
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
				
				if(tup.mobile.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_mobile_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.model.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_model_\"";
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
			inline std::string  Computer::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Computer::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Computer::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.cost.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.cost.value(), idx + 1);
					idx++;
				}
				
				if(tup.equipmentInterval.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.equipmentInterval.value(), idx + 1);
					idx++;
				}
				
				if(tup.equipmentStamp.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.equipmentStamp.value(), idx + 1);
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
				
				if(tup.mobile.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.mobile.value(), idx + 1);
					idx++;
				}
				
				if(tup.model.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.model.value(), idx + 1);
					idx++;
				}
				
				if(tup.securityStatus.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.securityStatus.value(), idx + 1);
					idx++;
				}
			}
			inline void  Computer::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
