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
				
			public:
				struct Domaindepartment
				{
					static const size_t amount = 2;
					static const char *values[amount];
				};
				
				
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
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Employee();
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
			
			template <class Oper> void Employee::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Employee
				Employee *c_Employee = _schema->getCategory<Employee>().get();
				o(this, c_Employee, (r3::fields::Enum<Employee::Domaindepartment>*)&tup.department, "department");
				o(this, c_Employee, (r3::fields::Money *)&tup.rateNight, "rateNight");
				o(this, c_Employee, (r3::fields::Money *)&tup.rateNormal, "rateNormal");
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, (r3::fields::Date *)&tup.birth, "birth");
				o(this, c_People, (r3::fields::String *)&tup.middlename, "middlename");
				o(this, c_People, (r3::fields::String *)&tup.name, "name");
				o(this, c_People, (r3::fields::Image *)&tup.photo, "photo");
				o(this, c_People, (r3::fields::Enum<People::Domainsex>*)&tup.sex, "sex");
				o(this, c_People, (r3::fields::String *)&tup.surname, "surname");
			}
			
			template <class Oper> void Employee::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Employee
				Employee *c_Employee = _schema->getCategory<Employee>().get();
				o(this, c_Employee, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2one<Employee>*)NULL,	"worker",	rs_dst);
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.observableServices,	"observableServices",	(r3::relations::Relation2n<People>*)NULL,	"observers",	rs_dst);
			}
			
			template <class Oper> void Employee::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Employee
				//People
			}
			
			inline Employee::Employee(Test *s)
				: CategoryBase<Employee>("Employee")
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
			
			inline void Employee::ins(Employee::Tuple &tup)
			{
				return CategoryBase<Employee>::ins(this, tup);
			}
			
			inline void Employee::ins(Employee::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Employee::upd(Employee::Tuple &tup)
			{
				return CategoryBase<Employee>::upd(this, tup);
			}
			
			inline void Employee::upd(Employee::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Employee::del(const fields::Id &id)
			{
				return CategoryBase<Employee>::del(this, id);
			}
			
			inline void Employee::del(Employee::Tuple &tup)
			{
				return CategoryBase<Employee>::del(this, tup);
			}
			
			inline void Employee::del(Employee::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Employee::Tuple_ptr  Employee::sel(const fields::Id &id)
			{
				return CategoryBase<Employee>::sel(this, id);
			}
			
			inline Employee::Tuple_ptr Employee::sel(Employee::Tuple_ptr tup)
			{
				return CategoryBase<Employee>::sel(this, tup);
			}
			
		}
	}
}

#endif
