// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Service_hpp_
#define _r3_model_Test_Service_hpp_

#include "r3/categoryBase.hpp"

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
				struct Service
						: public TupleBase<Service>
				{
					// Service
					r3::fields::Bool archive;
					r3::fields::String comment;
					r3::fields::Date created;
					r3::fields::String description;
					r3::relations::Relation2one<Client> client;
					r3::relations::Relation2n<People> observers;
					r3::relations::Relation2n<Stock> stocks;
					r3::relations::Relation2n<ServicePart> parts;
					r3::relations::Relation2one<Employee> worker;
				};
				typedef boost::shared_ptr<Service> Service_ptr;
				
			}
			
			class Service
				: public CategoryBase<Test, Service, tuple::Service>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuple::Service Tuple;
				typedef tuple::Service_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Service();
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
				Service(Test *s);
				
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
			typedef boost::shared_ptr<Service> Service_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Service::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Service::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Service
				Service *c_Service = _schema->getCategory<Service>().get();
				o(this, c_Service, (r3::fields::Bool *)&tup.archive, "archive");
				o(this, c_Service, (r3::fields::String *)&tup.comment, "comment");
				o(this, c_Service, (r3::fields::Date *)&tup.created, "created");
				o(this, c_Service, (r3::fields::String *)&tup.description, "description");
			}
			
			template <class Oper> void Service::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Service
				Service *c_Service = _schema->getCategory<Service>().get();
				o(this, c_Service, _schema->getCategory<Client>().get(), (r3::relations::Relation2one<Client>*)&tup.client,	"client",	(r3::relations::Relation2n<Service>*)NULL,	"services",	rs_src);
				o(this, c_Service, _schema->getCategory<People>().get(), (r3::relations::Relation2n<People>*)&tup.observers,	"observers",	(r3::relations::Relation2n<Service>*)NULL,	"observableServices",	rs_src);
				o(this, c_Service, _schema->getCategory<Stock>().get(), (r3::relations::Relation2n<Stock>*)&tup.stocks,	"stocks",	(r3::relations::Relation2n<Service>*)NULL,	"services",	rs_src);
				o(this, c_Service, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2n<ServicePart>*)&tup.parts,	"parts",	(r3::relations::Relation2one<Service>*)NULL,	"service",	rs_src);
				o(this, c_Service, _schema->getCategory<Employee>().get(), (r3::relations::Relation2one<Employee>*)&tup.worker,	"worker",	(r3::relations::Relation2n<Service>*)NULL,	"services",	rs_src);
			}
			
			template <class Oper> void Service::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Service
			}
			
			inline Service::Service(Test *s)
				: CategoryBase<Test, Service, tuple::Service>("Service")
				, _schema(s)
			{
			}
			
			inline Service::~Service()
			{
			}
			
			inline Test *Service::schema()
			{
				return _schema;
			}
			
			inline void Service::ins(Service::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Service::ins(Service::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Service::upd(Service::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Service::upd(Service::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Service::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Service::del(Service::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Service::del(Service::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Service::Tuple_ptr  Service::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Service::Tuple_ptr Service::sel(Service::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Service::tupleFillKey(Tuple &tup)
			{
				std::string res(4, '0');
				
				if(tup.archive.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.comment.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.created.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.description.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				return res;
			}
			inline std::string  Service::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
				if(tup.archive.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_archive_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.comment.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_comment_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.created.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_created_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.description.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_description_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  Service::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Service::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Service::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.archive.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.archive.value(), idx + 1);
					idx++;
				}
				
				if(tup.comment.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.comment.value(), idx + 1);
					idx++;
				}
				
				if(tup.created.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.created.value(), idx + 1);
					idx++;
				}
				
				if(tup.description.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.description.value(), idx + 1);
					idx++;
				}
			}
			inline void  Service::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
