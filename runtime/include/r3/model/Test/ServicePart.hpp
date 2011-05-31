// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_ServicePart_hpp_
#define _r3_model_Test_ServicePart_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			class ServicePart
				: public CategoryBase<ServicePart>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public CategoryBase<ServicePart>::Tuple
				{
					// ServicePart
					r3::fields::String comment;
					r3::fields::Money cost;
					r3::fields::DateTimeInterval duration;
					r3::fields::Date start;
					r3::fields::Date stop;
					r3::relations::Relation2n<Document> documents;
					r3::relations::Relation2one<Service> service;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~ServicePart();
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
				ServicePart(Test *s);
				
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
			typedef boost::shared_ptr<ServicePart> ServicePart_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void ServicePart::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void ServicePart::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, (r3::fields::String *)&tup.comment, "comment");
				o(this, c_ServicePart, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_ServicePart, (r3::fields::DateTimeInterval *)&tup.duration, "duration");
				o(this, c_ServicePart, (r3::fields::Date *)&tup.start, "start");
				o(this, c_ServicePart, (r3::fields::Date *)&tup.stop, "stop");
			}
			
			template <class Oper> void ServicePart::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n<Document>*)&tup.documents,	"documents",	(r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	rs_src);
				o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one<Service>*)&tup.service,	"service",	(r3::relations::Relation2n<ServicePart>*)NULL,	"parts",	rs_dst);
			}
			
			template <class Oper> void ServicePart::enumIndicesFromBasesAndSelf(Oper o)
			{
				//ServicePart
			}
			
			inline ServicePart::ServicePart(Test *s)
				: CategoryBase<ServicePart>("ServicePart")
				, _schema(s)
			{
			}
			
			inline ServicePart::~ServicePart()
			{
			}
			
			inline Test *ServicePart::schema()
			{
				return _schema;
			}
			
			inline void ServicePart::ins(ServicePart::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void ServicePart::ins(ServicePart::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void ServicePart::upd(ServicePart::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void ServicePart::upd(ServicePart::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void ServicePart::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void ServicePart::del(ServicePart::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void ServicePart::del(ServicePart::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline ServicePart::Tuple_ptr  ServicePart::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline ServicePart::Tuple_ptr ServicePart::sel(ServicePart::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  ServicePart::tupleFillKey(Tuple &tup)
			{
				std::string res(5, '0');
				
				if(tup.comment.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.cost.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.duration.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.start.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				if(tup.stop.fvs() != fields::fvs_notset) {
					res[4] = '1';
				}
				
				return res;
			}
			inline std::string  ServicePart::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
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
				
				if(tup.duration.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_duration_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.start.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_start_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.stop.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_stop_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  ServicePart::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  ServicePart::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  ServicePart::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.comment.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.comment.value(), idx + 1);
					idx++;
				}
				
				if(tup.cost.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.cost.value(), idx + 1);
					idx++;
				}
				
				if(tup.duration.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.duration.value(), idx + 1);
					idx++;
				}
				
				if(tup.start.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.start.value(), idx + 1);
					idx++;
				}
				
				if(tup.stop.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.stop.value(), idx + 1);
					idx++;
				}
			}
			inline void  ServicePart::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
