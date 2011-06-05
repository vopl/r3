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
		
			namespace tuples
			{
				struct Service
						: public TupleBase<Service>
				{
					// Service
					r3::fields::Bool archive;
					r3::fields::String comment;
					r3::fields::Date created;
					r3::fields::String description;
					r3::relations::Relation2one<s_Test::Client> client;
					r3::relations::Relation2n<s_Test::People> observers;
					r3::relations::Relation2n<s_Test::Stock> stocks;
					r3::relations::Relation2one<s_Test::Employee> worker;
					r3::relations::Relation2n<s_Test::ServicePart> parts;
					
					static const size_t _fieldsAmount = 4;
					static const size_t _relationsAmount = 5;
					
				};
				typedef boost::shared_ptr<Service> Service_ptr;
				
			}
			
			class Service
				: public CategoryBase<Test, Service, tuples::Service>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Service Tuple;
				typedef tuples::Service_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Service();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Service(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Service> Service_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Service::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Service::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Service
				Service *c_Service = _schema->getCategory<Service>().get();
				o(this, c_Service, &tup.archive, "archive");
				o(this, c_Service, &tup.comment, "comment");
				o(this, c_Service, &tup.created, "created");
				o(this, c_Service, &tup.description, "description");
			}
			
			template <class Oper> void Service::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Service
				Service *c_Service = _schema->getCategory<Service>().get();
				o(this, c_Service, _schema->getCategory<Client>().get(), &tup.client,	"client",	(r3::relations::Relation2n<s_Test::Service>*)NULL,	"services",	rs_src);
				o(this, c_Service, _schema->getCategory<People>().get(), &tup.observers,	"observers",	(r3::relations::Relation2n<s_Test::Service>*)NULL,	"observableServices",	rs_src);
				o(this, c_Service, _schema->getCategory<Stock>().get(), &tup.stocks,	"stocks",	(r3::relations::Relation2n<s_Test::Service>*)NULL,	"services",	rs_src);
				o(this, c_Service, _schema->getCategory<Employee>().get(), &tup.worker,	"worker",	(r3::relations::Relation2n<s_Test::Service>*)NULL,	"services",	rs_src);
				o(this, c_Service, _schema->getCategory<ServicePart>().get(), &tup.parts,	"parts",	(r3::relations::Relation2one<s_Test::Service>*)NULL,	"service",	rs_src);
			}
			
			template <class Oper> void Service::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Service
			}
			
			inline Service::Service(Test *s)
				: CategoryBase<Test, Service, tuples::Service>("Service")
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
			
		}
	}
}

#endif
