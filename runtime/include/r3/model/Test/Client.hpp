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
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Client();
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
			
			template <class Oper> void Client::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Client
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, (r3::fields::Date *)&tup.birth, "birth");
				o(this, c_People, (r3::fields::String *)&tup.middlename, "middlename");
				o(this, c_People, (r3::fields::String *)&tup.name, "name");
				o(this, c_People, (r3::fields::Image *)&tup.photo, "photo");
				o(this, c_People, (r3::fields::Enum<People::Domainsex>*)&tup.sex, "sex");
				o(this, c_People, (r3::fields::String *)&tup.surname, "surname");
			}
			
			template <class Oper> void Client::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Client
				Client *c_Client = _schema->getCategory<Client>().get();
				o(this, c_Client, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2one<Client>*)NULL,	"client",	rs_dst);
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.observableServices,	"observableServices",	(r3::relations::Relation2n<People>*)NULL,	"observers",	rs_dst);
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
			
			inline void Client::ins(Client::Tuple &tup)
			{
				return CategoryBase<Client>::ins(this, tup);
			}
			
			inline void Client::ins(Client::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Client::upd(Client::Tuple &tup)
			{
				return CategoryBase<Client>::upd(this, tup);
			}
			
			inline void Client::upd(Client::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Client::del(const fields::Id &id)
			{
				return CategoryBase<Client>::del(this, id);
			}
			
			inline void Client::del(Client::Tuple &tup)
			{
				return CategoryBase<Client>::del(this, tup);
			}
			
			inline void Client::del(Client::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Client::Tuple_ptr  Client::sel(const fields::Id &id)
			{
				return CategoryBase<Client>::sel(this, id);
			}
			
			inline Client::Tuple_ptr Client::sel(Client::Tuple_ptr tup)
			{
				return CategoryBase<Client>::sel(this, tup);
			}
			
		}
	}
}

#endif
