// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Client_hpp_
#define _r3_model_Test_Client_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/Test/People.hpp"

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
				struct Client
						: public TupleBase<Client>
				{
					// Client
					r3::relations::Relation2n<Service> services;
					// People
					r3::fields::Date birth;
					r3::fields::String middlename;
					r3::fields::String name;
					r3::fields::Image photo;
					r3::fields::Enum<DomainPeoplesex> sex;
					r3::fields::String surname;
					r3::relations::Relation2n<Service> observableServices;
					
					static const size_t _fieldsAmount = 6;
					static const size_t _relationsAmount = 2;
					
				};
				typedef boost::shared_ptr<Client> Client_ptr;
				
			}
			
			class Client
				: public CategoryBase<Test, Client, tuples::Client>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Client Tuple;
				typedef tuples::Client_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Client();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Client(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Client> Client_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Client::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<People>().get());
			}
			
			template <class Oper> void Client::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Client
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, &tup.birth, "birth");
				o(this, c_People, &tup.middlename, "middlename");
				o(this, c_People, &tup.name, "name");
				o(this, c_People, &tup.photo, "photo");
				o(this, c_People, &tup.sex, "sex");
				o(this, c_People, &tup.surname, "surname");
			}
			
			template <class Oper> void Client::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Client
				Client *c_Client = _schema->getCategory<Client>().get();
				o(this, c_Client, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2one<Client>*)NULL,	"client",	rs_dst);
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.observableServices,	"observableServices",	(r3::relations::Relation2n<People>*)NULL,	"observers",	rs_dst);
			}
			
			template <class Oper> void Client::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Client
				//People
			}
			
			inline Client::Client(Test *s)
				: CategoryBase<Test, Client, tuples::Client>("Client")
				, _schema(s)
			{
			}
			
			inline Client::~Client()
			{
			}
			
			inline Test *Client::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
