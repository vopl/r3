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
		
			namespace tuples
			{
				struct WebSite
						: public TupleBase<WebSite>
				{
					// ServicePart
					r3::fields::String comment;
					r3::fields::Money cost;
					r3::fields::DateTimeInterval duration;
					r3::fields::Date start;
					r3::fields::Date stop;
					r3::relations::Relation2n<s_Test::Document> documents;
					r3::relations::Relation2one<s_Test::Service> service;
					// WebSite
					r3::fields::String host;
					r3::fields::String url;
					r3::relations::Relation2n<s_Test::Mockup> mockups;
					
					static const size_t _fieldsAmount = 7;
					static const size_t _relationsAmount = 3;
					
				};
				typedef boost::shared_ptr<WebSite> WebSite_ptr;
				
			}
			
			class WebSite
				: public CategoryBase<Test, WebSite, tuples::WebSite>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::WebSite Tuple;
				typedef tuples::WebSite_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~WebSite();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				WebSite(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<WebSite> WebSite_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void WebSite::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<ServicePart>().get());
			}
			
			template <class Oper> void WebSite::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, &tup.comment, "comment");
				o(this, c_ServicePart, &tup.cost, "cost");
				o(this, c_ServicePart, &tup.duration, "duration");
				o(this, c_ServicePart, &tup.start, "start");
				o(this, c_ServicePart, &tup.stop, "stop");
				//WebSite
				WebSite *c_WebSite = _schema->getCategory<WebSite>().get();
				o(this, c_WebSite, &tup.host, "host");
				o(this, c_WebSite, &tup.url, "url");
			}
			
			template <class Oper> void WebSite::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, _schema->getCategory<Document>().get(), &tup.documents,	"documents",	(r3::relations::Relation2one<s_Test::ServicePart>*)NULL,	"servicePart",	rs_src);
				o(this, c_ServicePart, _schema->getCategory<Service>().get(), &tup.service,	"service",	(r3::relations::Relation2n<s_Test::ServicePart>*)NULL,	"parts",	rs_dst);
				//WebSite
				WebSite *c_WebSite = _schema->getCategory<WebSite>().get();
				o(this, c_WebSite, _schema->getCategory<Mockup>().get(), &tup.mockups,	"mockups",	(r3::relations::Relation2one<s_Test::WebSite>*)NULL,	"webSite",	rs_dst);
			}
			
			template <class Oper> void WebSite::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//ServicePart
				//WebSite
			}
			
			inline WebSite::WebSite(Test *s)
				: CategoryBase<Test, WebSite, tuples::WebSite>("WebSite")
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
			
		}
	}
}

#endif
