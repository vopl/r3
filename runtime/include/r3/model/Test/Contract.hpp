// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Contract_hpp_
#define _r3_model_Test_Contract_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/Test/Document.hpp"

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
				struct Contract
						: public TupleBase<Contract>
				{
					// Contract
					r3::fields::Int32 param1;
					r3::fields::Int64 param2;
					r3::fields::Int8 param3;
					r3::fields::Real64 param4;
					// Document
					r3::fields::Date creation;
					r3::fields::File file;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<ServicePart> servicePart;
				};
				typedef boost::shared_ptr<Contract> Contract_ptr;
				
			}
			
			class Contract
				: public CategoryBase<Test, Contract, tuple::Contract>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuple::Contract Tuple;
				typedef tuple::Contract_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Contract();
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
				Contract(Test *s);
				
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
			typedef boost::shared_ptr<Contract> Contract_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Contract::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Document>().get());
			}
			
			template <class Oper> void Contract::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Contract
				Contract *c_Contract = _schema->getCategory<Contract>().get();
				o(this, c_Contract, (r3::fields::Int32 *)&tup.param1, "param1");
				o(this, c_Contract, (r3::fields::Int64 *)&tup.param2, "param2");
				o(this, c_Contract, (r3::fields::Int8 *)&tup.param3, "param3");
				o(this, c_Contract, (r3::fields::Real64 *)&tup.param4, "param4");
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)&tup.creation, "creation");
				o(this, c_Document, (r3::fields::File *)&tup.file, "file");
				o(this, c_Document, (r3::fields::Timestamp *)&tup.lastModified, "lastModified");
			}
			
			template <class Oper> void Contract::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Contract
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
			}
			
			template <class Oper> void Contract::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Contract
				//Document
			}
			
			inline Contract::Contract(Test *s)
				: CategoryBase<Test, Contract, tuple::Contract>("Contract")
				, _schema(s)
			{
			}
			
			inline Contract::~Contract()
			{
			}
			
			inline Test *Contract::schema()
			{
				return _schema;
			}
			
			inline void Contract::ins(Contract::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Contract::ins(Contract::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Contract::upd(Contract::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Contract::upd(Contract::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Contract::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Contract::del(Contract::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Contract::del(Contract::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Contract::Tuple_ptr  Contract::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Contract::Tuple_ptr Contract::sel(Contract::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Contract::tupleFillKey(Tuple &tup)
			{
				std::string res(7, '0');
				
				if(tup.creation.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.file.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.lastModified.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.param1.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				if(tup.param2.fvs() != fields::fvs_notset) {
					res[4] = '1';
				}
				
				if(tup.param3.fvs() != fields::fvs_notset) {
					res[5] = '1';
				}
				
				if(tup.param4.fvs() != fields::fvs_notset) {
					res[6] = '1';
				}
				
				return res;
			}
			inline std::string  Contract::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
				if(tup.creation.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_creation_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.file.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_file_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.lastModified.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_lastModified_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.param1.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_param1_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.param2.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_param2_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.param3.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_param3_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.param4.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_param4_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  Contract::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Contract::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Contract::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.creation.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.creation.value(), idx + 1);
					idx++;
				}
				
				if(tup.file.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.file.value(), idx + 1);
					idx++;
				}
				
				if(tup.lastModified.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.lastModified.value(), idx + 1);
					idx++;
				}
				
				if(tup.param1.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.param1.value(), idx + 1);
					idx++;
				}
				
				if(tup.param2.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.param2.value(), idx + 1);
					idx++;
				}
				
				if(tup.param3.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.param3.value(), idx + 1);
					idx++;
				}
				
				if(tup.param4.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.param4.value(), idx + 1);
					idx++;
				}
			}
			inline void  Contract::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
