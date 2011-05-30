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
						: public ServicePart::Tuple
				{
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
				return CategoryBase<WebSite>::ins(this, tup);
			}
			
			inline void WebSite::ins(WebSite::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void WebSite::upd(WebSite::Tuple &tup)
			{
				return CategoryBase<WebSite>::upd(this, tup);
			}
			
			inline void WebSite::upd(WebSite::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void WebSite::del(const fields::Id &id)
			{
				return CategoryBase<WebSite>::del(this, id);
			}
			
			inline void WebSite::del(WebSite::Tuple &tup)
			{
				return CategoryBase<WebSite>::del(this, tup);
			}
			
			inline void WebSite::del(WebSite::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline WebSite::Tuple_ptr  WebSite::sel(const fields::Id &id)
			{
				return CategoryBase<WebSite>::sel(this, id);
			}
			
			inline WebSite::Tuple_ptr WebSite::sel(WebSite::Tuple_ptr tup)
			{
				return CategoryBase<WebSite>::sel(this, tup);
			}
			
		}
	}
}

#endif
