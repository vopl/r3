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
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<People>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Client
					//People
					People *c_People = _schema->getCategory<People>().get();
					o(this, c_People, (r3::fields::Date *)NULL, "Birth");
					o(this, c_People, (r3::fields::String *)NULL, "Middlename");
					o(this, c_People, (r3::fields::String *)NULL, "Name");
					o(this, c_People, (r3::fields::Image *)NULL, "Photo");
					o(this, c_People, (r3::fields::Enum<People::DomainSex>*)NULL, "Sex");
					o(this, c_People, (r3::fields::String *)NULL, "Surname");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Client
					Client *c_Client = _schema->getCategory<Client>().get();
					o(this, c_Client, _schema->getCategory<Service>().get(), (r3::relations::Relation2n *)NULL,	"services",	(r3::relations::Relation2one *)NULL,	"client",	rs_dst);
					//People
					People *c_People = _schema->getCategory<People>().get();
					o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n *)NULL,	"observableServices",	(r3::relations::Relation2n *)NULL,	"observers",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Client
					//People
				}
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Client(Schema *s)
					: CategoryBase<Client>("Client")
					, _schema(s)
				{
				}
				
				~Client()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Client> Client_ptr;
		}
	}
}

#endif
