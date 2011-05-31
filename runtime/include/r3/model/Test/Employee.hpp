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
		
			namespace tuples
			{
				struct DomainEmployeedepartment
				{
					static const size_t amount = 2;
					static const char *values[amount];
				};
				
				struct Employee
						: public TupleBase<Employee>
				{
					// Employee
					r3::fields::Enum<DomainEmployeedepartment> department;
					r3::fields::Money rateNight;
					r3::fields::Money rateNormal;
					r3::relations::Relation2n<Service> services;
					// People
					r3::fields::Date birth;
					r3::fields::String middlename;
					r3::fields::String name;
					r3::fields::Image photo;
					r3::fields::Enum<DomainPeoplesex> sex;
					r3::fields::String surname;
					r3::relations::Relation2n<Service> observableServices;
					
					static const size_t _fieldsAmount = 9;
					static const size_t _relationsAmount = 2;
					
				};
				typedef boost::shared_ptr<Employee> Employee_ptr;
				
			}
			
			class Employee
				: public CategoryBase<Test, Employee, tuples::Employee>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Employee Tuple;
				typedef tuples::Employee_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Employee();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Employee(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Employee> Employee_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Employee::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<People>().get());
			}
			
			template <class Oper> void Employee::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Employee
				Employee *c_Employee = _schema->getCategory<Employee>().get();
				o(this, c_Employee, (r3::fields::Enum<tuples::DomainEmployeedepartment>*)&tup.department, "department");
				o(this, c_Employee, (r3::fields::Money *)&tup.rateNight, "rateNight");
				o(this, c_Employee, (r3::fields::Money *)&tup.rateNormal, "rateNormal");
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, (r3::fields::Date *)&tup.birth, "birth");
				o(this, c_People, (r3::fields::String *)&tup.middlename, "middlename");
				o(this, c_People, (r3::fields::String *)&tup.name, "name");
				o(this, c_People, (r3::fields::Image *)&tup.photo, "photo");
				o(this, c_People, (r3::fields::Enum<tuples::DomainPeoplesex>*)&tup.sex, "sex");
				o(this, c_People, (r3::fields::String *)&tup.surname, "surname");
			}
			
			template <class Oper> void Employee::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Employee
				Employee *c_Employee = _schema->getCategory<Employee>().get();
				o(this, c_Employee, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2one<Employee>*)NULL,	"worker",	rs_dst);
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.observableServices,	"observableServices",	(r3::relations::Relation2n<People>*)NULL,	"observers",	rs_dst);
			}
			
			template <class Oper> void Employee::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Employee
				//People
			}
			
			inline Employee::Employee(Test *s)
				: CategoryBase<Test, Employee, tuples::Employee>("Employee")
				, _schema(s)
			{
			}
			
			inline Employee::~Employee()
			{
			}
			
			inline Test *Employee::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
