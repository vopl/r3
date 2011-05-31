// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_WebSite_hpp_
#define _r3_model_Test_WebSite_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/Test/ServicePart.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			class WebSite
				: public CategoryBase<WebSite>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public CategoryBase<WebSite>::Tuple
				{
					// ServicePart
					r3::fields::String comment;
					r3::fields::Money cost;
					r3::fields::DateTimeInterval duration;
					r3::fields::Date start;
					r3::fields::Date stop;
					r3::relations::Relation2n<Document> documents;
					r3::relations::Relation2one<Service> service;
					// WebSite
					r3::fields::String host;
					r3::fields::String url;
					r3::relations::Relation2n<Mockup> mockups;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~WebSite();
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
				WebSite(Test *s);
				
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
			typedef boost::shared_ptr<WebSite> WebSite_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void WebSite::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<ServicePart>().get());
			}
			
			template <class Oper> void WebSite::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, (r3::fields::String *)&tup.comment, "comment");
				o(this, c_ServicePart, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_ServicePart, (r3::fields::DateTimeInterval *)&tup.duration, "duration");
				o(this, c_ServicePart, (r3::fields::Date *)&tup.start, "start");
				o(this, c_ServicePart, (r3::fields::Date *)&tup.stop, "stop");
				//WebSite
				WebSite *c_WebSite = _schema->getCategory<WebSite>().get();
				o(this, c_WebSite, (r3::fields::String *)&tup.host, "host");
				o(this, c_WebSite, (r3::fields::String *)&tup.url, "url");
			}
			
			template <class Oper> void WebSite::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n<Document>*)&tup.documents,	"documents",	(r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	rs_src);
				o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one<Service>*)&tup.service,	"service",	(r3::relations::Relation2n<ServicePart>*)NULL,	"parts",	rs_dst);
				//WebSite
				WebSite *c_WebSite = _schema->getCategory<WebSite>().get();
				o(this, c_WebSite, _schema->getCategory<Mockup>().get(), (r3::relations::Relation2n<Mockup>*)&tup.mockups,	"mockups",	(r3::relations::Relation2one<WebSite>*)NULL,	"webSite",	rs_dst);
			}
			
			template <class Oper> void WebSite::enumIndicesFromBasesAndSelf(Oper o)
			{
				//ServicePart
				//WebSite
			}
			
			inline WebSite::WebSite(Test *s)
				: CategoryBase<WebSite>("WebSite")
				, _schema(s)
			{
			}
			
			inline WebSite::~WebSite()
			{
			}
			
			inline Test *WebSite::schema()
			{
				return _schema;
			}
			
			inline void WebSite::ins(WebSite::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void WebSite::ins(WebSite::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void WebSite::upd(WebSite::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void WebSite::upd(WebSite::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void WebSite::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void WebSite::del(WebSite::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void WebSite::del(WebSite::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline WebSite::Tuple_ptr  WebSite::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline WebSite::Tuple_ptr WebSite::sel(WebSite::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  WebSite::tupleFillKey(Tuple &tup)
			{
				std::string res(7, '0');
				
				if(tup.comment.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.cost.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.duration.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.host.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				if(tup.start.fvs() != fields::fvs_notset) {
					res[4] = '1';
				}
				
				if(tup.stop.fvs() != fields::fvs_notset) {
					res[5] = '1';
				}
				
				if(tup.url.fvs() != fields::fvs_notset) {
					res[6] = '1';
				}
				
				return res;
			}
			inline std::string  WebSite::tupleInsSql(Tuple &tup)
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
				
				if(tup.host.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_host_\"";
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
				
				if(tup.url.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_url_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  WebSite::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  WebSite::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  WebSite::tupleInsBind(Tuple &tup, pgc::Statement &stm)
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
				
				if(tup.host.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.host.value(), idx + 1);
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
				
				if(tup.url.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.url.value(), idx + 1);
					idx++;
				}
			}
			inline void  WebSite::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
