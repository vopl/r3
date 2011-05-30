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
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Service();
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
			
			template <class Oper> void Service::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Service
				Service *c_Service = _schema->getCategory<Service>().get();
				o(this, c_Service, (r3::fields::Bool *)&tup.archive, "archive");
				o(this, c_Service, (r3::fields::String *)&tup.comment, "comment");
				o(this, c_Service, (r3::fields::Date *)&tup.created, "created");
				o(this, c_Service, (r3::fields::String *)&tup.description, "description");
			}
			
			template <class Oper> void Service::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Service
				Service *c_Service = _schema->getCategory<Service>().get();
				o(this, c_Service, _schema->getCategory<Client>().get(), (r3::relations::Relation2one<Client>*)&tup.client,	"client",	(r3::relations::Relation2n<Service>*)NULL,	"services",	rs_src);
				o(this, c_Service, _schema->getCategory<People>().get(), (r3::relations::Relation2n<People>*)&tup.observers,	"observers",	(r3::relations::Relation2n<Service>*)NULL,	"observableServices",	rs_src);
				o(this, c_Service, _schema->getCategory<Stock>().get(), (r3::relations::Relation2n<Stock>*)&tup.stocks,	"stocks",	(r3::relations::Relation2n<Service>*)NULL,	"services",	rs_src);
				o(this, c_Service, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2n<ServicePart>*)&tup.parts,	"parts",	(r3::relations::Relation2one<Service>*)NULL,	"service",	rs_src);
				o(this, c_Service, _schema->getCategory<Employee>().get(), (r3::relations::Relation2one<Employee>*)&tup.worker,	"worker",	(r3::relations::Relation2n<Service>*)NULL,	"services",	rs_src);
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
			
			inline void Service::ins(Service::Tuple &tup)
			{
				return CategoryBase<Service>::ins(this, tup);
			}
			
			inline void Service::ins(Service::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Service::upd(Service::Tuple &tup)
			{
				return CategoryBase<Service>::upd(this, tup);
			}
			
			inline void Service::upd(Service::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Service::del(const fields::Id &id)
			{
				return CategoryBase<Service>::del(this, id);
			}
			
			inline void Service::del(Service::Tuple &tup)
			{
				return CategoryBase<Service>::del(this, tup);
			}
			
			inline void Service::del(Service::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Service::Tuple_ptr  Service::sel(const fields::Id &id)
			{
				return CategoryBase<Service>::sel(this, id);
			}
			
			inline Service::Tuple_ptr Service::sel(Service::Tuple_ptr tup)
			{
				return CategoryBase<Service>::sel(this, tup);
			}
			
		}
	}
}

#endif
