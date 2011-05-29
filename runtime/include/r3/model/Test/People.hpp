// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_People_hpp_
#define _r3_model_Test_People_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			//deriveds
			class Client;
			typedef boost::shared_ptr<Client> Client_ptr;
			class Employee;
			typedef boost::shared_ptr<Employee> Employee_ptr;
			
			class People
				: public CategoryBase<People>
			{
			
			public:
				static const bool isAbstract = false;
				
				struct DomainSex
				{
					static const size_t amount = 0;
					static const char *values[amount];
				};
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
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
					//People
					People *c_People = _schema->getCategory<People>().get();
					o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n *)NULL,	"observableServices",	(r3::relations::Relation2n *)NULL,	"observers",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//People
				}
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				People(Schema *s)
					: CategoryBase<People>("People")
					, _schema(s)
				{
				}
				
				~People()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<People> People_ptr;
		}
	}
}

#endif
