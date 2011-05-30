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
		
			class Service
				: public CategoryBase<Service>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public CategoryBase<Service>::Tuple
				{
					r3::fields::Bool archive;
					r3::fields::String comment;
					r3::fields::Date created;
					r3::fields::String description;
					r3::relations::Relation2one<Client> client;
					r3::relations::Relation2n<People> observers;
					r3::relations::Relation2n<Stock> stocks;
					r3::relations::Relation2n<ServicePart> parts;
					r3::relations::Relation2one<Employee> worker;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Service();
				Test *schema();
				
				void ins(Tuple &tup);
				void ins(Tuple_ptr tup);
				
				void upd(Tuple &tup);
				void upd(Tuple_ptr tup);
				
				void del(const boost::int64_t &id);
				void del(Tuple &tup);
				void del(Tuple_ptr tup);
				
				Tuple_ptr sel(const boost::int64_t &id);
				Tuple_ptr sel(Tuple_ptr tup);
				
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
			
			template <class Oper> void Service::enumFieldsFromBasesAndSelf(Oper o)
			{
				//Service
				Service *c_Service = _schema->getCategory<Service>().get();
				o(this, c_Service, (r3::fields::Bool *)NULL, "archive");
				o(this, c_Service, (r3::fields::String *)NULL, "comment");
				o(this, c_Service, (r3::fields::Date *)NULL, "created");
				o(this, c_Service, (r3::fields::String *)NULL, "description");
			}
			
			template <class Oper> void Service::enumRelationsFromBasesAndSelf(Oper o)
			{
				//Service
				Service *c_Service = _schema->getCategory<Service>().get();
				o(this, c_Service, _schema->getCategory<Client>().get(), (r3::relations::Relation2one<Client>*)NULL,	"client",	(r3::relations::Relation2n<Service>*)NULL,	"services",	rs_src);
				o(this, c_Service, _schema->getCategory<People>().get(), (r3::relations::Relation2n<People>*)NULL,	"observers",	(r3::relations::Relation2n<Service>*)NULL,	"observableServices",	rs_src);
				o(this, c_Service, _schema->getCategory<Stock>().get(), (r3::relations::Relation2n<Stock>*)NULL,	"stocks",	(r3::relations::Relation2n<Service>*)NULL,	"services",	rs_src);
				o(this, c_Service, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2n<ServicePart>*)NULL,	"parts",	(r3::relations::Relation2one<Service>*)NULL,	"service",	rs_src);
				o(this, c_Service, _schema->getCategory<Employee>().get(), (r3::relations::Relation2one<Employee>*)NULL,	"worker",	(r3::relations::Relation2n<Service>*)NULL,	"services",	rs_src);
			}
			
			template <class Oper> void Service::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Service
			}
			
			inline Service::Service(Test *s)
				: CategoryBase<Service>("Service")
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
