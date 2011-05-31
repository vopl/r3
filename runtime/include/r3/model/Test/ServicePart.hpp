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
		
			namespace tuples
			{
				struct ServicePart
						: public TupleBase<ServicePart>
				{
					// ServicePart
					r3::fields::String comment;
					r3::fields::Money cost;
					r3::fields::DateTimeInterval duration;
					r3::fields::Date start;
					r3::fields::Date stop;
					r3::relations::Relation2n<Document> documents;
					r3::relations::Relation2one<Service> service;
					
					static const size_t _fieldsAmount = 5;
					static const size_t _relationsAmount = 2;
					
				};
				typedef boost::shared_ptr<ServicePart> ServicePart_ptr;
				
			}
			
			class ServicePart
				: public CategoryBase<Test, ServicePart, tuples::ServicePart>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::ServicePart Tuple;
				typedef tuples::ServicePart_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~ServicePart();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				ServicePart(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<ServicePart> ServicePart_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void ServicePart::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void ServicePart::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, (r3::fields::String *)&tup.comment, "comment");
				o(this, c_ServicePart, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_ServicePart, (r3::fields::DateTimeInterval *)&tup.duration, "duration");
				o(this, c_ServicePart, (r3::fields::Date *)&tup.start, "start");
				o(this, c_ServicePart, (r3::fields::Date *)&tup.stop, "stop");
			}
			
			template <class Oper> void ServicePart::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n<Document>*)&tup.documents,	"documents",	(r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	rs_src);
				o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one<Service>*)&tup.service,	"service",	(r3::relations::Relation2n<ServicePart>*)NULL,	"parts",	rs_dst);
			}
			
			template <class Oper> void ServicePart::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//ServicePart
			}
			
			inline ServicePart::ServicePart(Test *s)
				: CategoryBase<Test, ServicePart, tuples::ServicePart>("ServicePart")
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
			
		}
	}
}

#endif