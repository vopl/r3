// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Employee_hpp_
#define _r3_model_Test_Employee_hpp_

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
		
			class Employee
				: public CategoryBase<Employee>
			{
			
			public:
				static const bool isAbstract = false;
				
				struct Domaindepartment
				{
					static const size_t amount = 2;
					static const char *values[amount];
				};
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<People>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Employee
					Employee *c_Employee = _schema->getCategory<Employee>().get();
					o(this, c_Employee, (r3::fields::Enum<Employee::Domaindepartment>*)NULL, "department");
					o(this, c_Employee, (r3::fields::Money *)NULL, "rateNight");
					o(this, c_Employee, (r3::fields::Money *)NULL, "rateNormal");
					//People
					People *c_People = _schema->getCategory<People>().get();
					o(this, c_People, (r3::fields::Date *)NULL, "birth");
					o(this, c_People, (r3::fields::String *)NULL, "middlename");
					o(this, c_People, (r3::fields::String *)NULL, "name");
					o(this, c_People, (r3::fields::Image *)NULL, "photo");
					o(this, c_People, (r3::fields::Enum<People::Domainsex>*)NULL, "sex");
					o(this, c_People, (r3::fields::String *)NULL, "surname");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Employee
					Employee *c_Employee = _schema->getCategory<Employee>().get();
					o(this, c_Employee, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)NULL,	"services",	(r3::relations::Relation2one<Employee>*)NULL,	"worker",	rs_dst);
					//People
					People *c_People = _schema->getCategory<People>().get();
					o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)NULL,	"observableServices",	(r3::relations::Relation2n<People>*)NULL,	"observers",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Employee
					//People
				}
				
			public:
				struct Tuple
						: public People::Tuple
				{
					r3::fields::Enum<Employee::Domaindepartment> department;
					r3::fields::Money rateNight;
					r3::fields::Money rateNormal;
					r3::relations::Relation2n<Service> services;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Employee(Schema *s)
					: CategoryBase<Employee>("Employee")
					, _schema(s)
				{
				}
				
				~Employee()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Employee> Employee_ptr;
		}
	}
}

#endif
