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
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
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
			
			template <class Oper> void WebSite::enumFieldsFromBasesAndSelf(Oper o)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, (r3::fields::String *)NULL, "comment");
				o(this, c_ServicePart, (r3::fields::Money *)NULL, "cost");
				o(this, c_ServicePart, (r3::fields::DateTimeInterval *)NULL, "duration");
				o(this, c_ServicePart, (r3::fields::Date *)NULL, "start");
				o(this, c_ServicePart, (r3::fields::Date *)NULL, "stop");
				//WebSite
				WebSite *c_WebSite = _schema->getCategory<WebSite>().get();
				o(this, c_WebSite, (r3::fields::String *)NULL, "host");
				o(this, c_WebSite, (r3::fields::String *)NULL, "url");
			}
			
			template <class Oper> void WebSite::enumRelationsFromBasesAndSelf(Oper o)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n<Document>*)NULL,	"documents",	(r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	rs_src);
				o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one<Service>*)NULL,	"service",	(r3::relations::Relation2n<ServicePart>*)NULL,	"parts",	rs_dst);
				//WebSite
				WebSite *c_WebSite = _schema->getCategory<WebSite>().get();
				o(this, c_WebSite, _schema->getCategory<Mockup>().get(), (r3::relations::Relation2n<Mockup>*)NULL,	"mockups",	(r3::relations::Relation2one<WebSite>*)NULL,	"webSite",	rs_dst);
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
			
		}
	}
}

#endif
