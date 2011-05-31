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
		
			namespace tuple
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
				};
				typedef boost::shared_ptr<Employee> Employee_ptr;
				
			}
			
			class Employee
				: public CategoryBase<Test, Employee, tuple::Employee>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuple::Employee Tuple;
				typedef tuple::Employee_ptr Tuple_ptr;
				
				typedef Test Schema;
				
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
				
			protected:
				std::string tupleFillKey(Tuple &tup);
				std::string tupleInsSql(Tuple &tup);
				std::string tupleUpdSql(Tuple &tup);
				std::string tupleSelSql(Tuple &tup);
				void tupleInsBind(Tuple &tup, pgc::Statement &stm);
				void tupleUpdBind(Tuple &tup, pgc::Statement &stm);
				
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
				o(this, c_Employee, (r3::fields::Enum<tuple::DomainEmployeedepartment>*)&tup.department, "department");
				o(this, c_Employee, (r3::fields::Money *)&tup.rateNight, "rateNight");
				o(this, c_Employee, (r3::fields::Money *)&tup.rateNormal, "rateNormal");
				//People
				People *c_People = _schema->getCategory<People>().get();
				o(this, c_People, (r3::fields::Date *)&tup.birth, "birth");
				o(this, c_People, (r3::fields::String *)&tup.middlename, "middlename");
				o(this, c_People, (r3::fields::String *)&tup.name, "name");
				o(this, c_People, (r3::fields::Image *)&tup.photo, "photo");
				o(this, c_People, (r3::fields::Enum<tuple::DomainPeoplesex>*)&tup.sex, "sex");
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
				: CategoryBase<Test, Employee, tuple::Employee>("Employee")
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
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Employee::ins(Employee::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Employee::upd(Employee::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Employee::upd(Employee::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Employee::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Employee::del(Employee::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Employee::del(Employee::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Employee::Tuple_ptr  Employee::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Employee::Tuple_ptr Employee::sel(Employee::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Employee::tupleFillKey(Tuple &tup)
			{
				std::string res(9, '0');
				
				if(tup.birth.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.department.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.middlename.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.name.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				if(tup.photo.fvs() != fields::fvs_notset) {
					res[4] = '1';
				}
				
				if(tup.rateNight.fvs() != fields::fvs_notset) {
					res[5] = '1';
				}
				
				if(tup.rateNormal.fvs() != fields::fvs_notset) {
					res[6] = '1';
				}
				
				if(tup.sex.fvs() != fields::fvs_notset) {
					res[7] = '1';
				}
				
				if(tup.surname.fvs() != fields::fvs_notset) {
					res[8] = '1';
				}
				
				return res;
			}
			inline std::string  Employee::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
				if(tup.birth.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_birth_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.department.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_department_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.middlename.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_middlename_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.name.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_name_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.photo.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_photo_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.rateNight.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_rateNight_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.rateNormal.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_rateNormal_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.sex.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_sex_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.surname.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_surname_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  Employee::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Employee::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Employee::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.birth.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.birth.value(), idx + 1);
					idx++;
				}
				
				if(tup.department.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.department.value(), idx + 1);
					idx++;
				}
				
				if(tup.middlename.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.middlename.value(), idx + 1);
					idx++;
				}
				
				if(tup.name.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.name.value(), idx + 1);
					idx++;
				}
				
				if(tup.photo.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.photo.value(), idx + 1);
					idx++;
				}
				
				if(tup.rateNight.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.rateNight.value(), idx + 1);
					idx++;
				}
				
				if(tup.rateNormal.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.rateNormal.value(), idx + 1);
					idx++;
				}
				
				if(tup.sex.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.sex.value(), idx + 1);
					idx++;
				}
				
				if(tup.surname.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.surname.value(), idx + 1);
					idx++;
				}
			}
			inline void  Employee::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
