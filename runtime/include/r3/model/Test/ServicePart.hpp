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
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//ServicePart
					ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
					o(this, c_ServicePart, (r3::fields::String *)NULL, "comment");
					o(this, c_ServicePart, (r3::fields::Money *)NULL, "cost");
					o(this, c_ServicePart, (r3::fields::DateTimeInterval *)NULL, "duration");
					o(this, c_ServicePart, (r3::fields::Date *)NULL, "start");
					o(this, c_ServicePart, (r3::fields::Date *)NULL, "stop");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//ServicePart
					ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
					o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n<Document>*)NULL,	"documents",	(r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	rs_src);
					o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one<Service>*)NULL,	"service",	(r3::relations::Relation2n<ServicePart>*)NULL,	"parts",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//ServicePart
				}
				
			public:
				struct Tuple
						: public CategoryBase<ServicePart>::Tuple
				{
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
