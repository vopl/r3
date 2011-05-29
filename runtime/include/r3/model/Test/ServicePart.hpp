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
		
			//deriveds
			class Program;
			typedef boost::shared_ptr<Program> Program_ptr;
			class WebSite;
			typedef boost::shared_ptr<WebSite> WebSite_ptr;
			
			class ServicePart
				: public CategoryBase<ServicePart>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//ServicePart
					ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
					o(this, c_ServicePart, (r3::fields::String *)NULL, "Comment");
					o(this, c_ServicePart, (r3::fields::Money *)NULL, "Cost");
					o(this, c_ServicePart, (r3::fields::DateTimeInterval *)NULL, "Duration");
					o(this, c_ServicePart, (r3::fields::Date *)NULL, "Start");
					o(this, c_ServicePart, (r3::fields::Date *)NULL, "Stop");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//ServicePart
					ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
					o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n *)NULL,	"documents",	(r3::relations::Relation2one *)NULL,	"servicePart",	rs_src);
					o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one *)NULL,	"service",	(r3::relations::Relation2n *)NULL,	"parts",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//ServicePart
				}
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				ServicePart(Schema *s)
					: CategoryBase<ServicePart>("ServicePart")
					, _schema(s)
				{
				}
				
				~ServicePart()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<ServicePart> ServicePart_ptr;
		}
	}
}

#endif
