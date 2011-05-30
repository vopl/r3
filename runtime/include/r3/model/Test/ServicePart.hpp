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
				return CategoryBase<ServicePart>::ins(this, tup);
			}
			
			inline void ServicePart::ins(ServicePart::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void ServicePart::upd(ServicePart::Tuple &tup)
			{
				return CategoryBase<ServicePart>::upd(this, tup);
			}
			
			inline void ServicePart::upd(ServicePart::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void ServicePart::del(const fields::Id &id)
			{
				return CategoryBase<ServicePart>::del(this, id);
			}
			
			inline void ServicePart::del(ServicePart::Tuple &tup)
			{
				return CategoryBase<ServicePart>::del(this, tup);
			}
			
			inline void ServicePart::del(ServicePart::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline ServicePart::Tuple_ptr  ServicePart::sel(const fields::Id &id)
			{
				return CategoryBase<ServicePart>::sel(this, id);
			}
			
			inline ServicePart::Tuple_ptr ServicePart::sel(ServicePart::Tuple_ptr tup)
			{
				return CategoryBase<ServicePart>::sel(this, tup);
			}
			
		}
	}
}

#endif
