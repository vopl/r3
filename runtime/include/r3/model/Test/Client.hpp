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
		
			class Client
				: public CategoryBase<Client>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public People::Tuple
				{
					r3::relations::Relation2n<Service> services;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				Client(Test *s);
				~Client();
				Test *schema();
				
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
			
			template <class Oper> void Client::enumFieldsFromBasesAndSelf(Oper o)
			{
				//Client
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, (r3::fields::Date *)NULL, "birth");
				o(this, c_People, (r3::fields::String *)NULL, "middlename");
				o(this, c_People, (r3::fields::String *)NULL, "name");
				o(this, c_People, (r3::fields::Image *)NULL, "photo");
				o(this, c_People, (r3::fields::Enum<People::Domainsex>*)NULL, "sex");
				o(this, c_People, (r3::fields::String *)NULL, "surname");
			}
			
			template <class Oper> void Client::enumRelationsFromBasesAndSelf(Oper o)
			{
				//Client
				Client *c_Client = _schema->getCategory<Client>().get();
				o(this, c_Client, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)NULL,	"services",	(r3::relations::Relation2one<Client>*)NULL,	"client",	rs_dst);
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)NULL,	"observableServices",	(r3::relations::Relation2n<People>*)NULL,	"observers",	rs_dst);
			}
			
			template <class Oper> void Client::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Client
				//People
			}
			
			inline Client::Client(Test *s)
				: CategoryBase<Client>("Client")
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
