// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_Department_hpp_
#define _r3_model_V1_Department_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/V1/Owner.hpp"

namespace r3
{
	namespace model
	{
	
		class V1;
		typedef boost::shared_ptr<V1> V1_ptr;
		
		namespace s_V1
		{
		
			namespace tuple
			{
				struct Department
						: public TupleBase<Department>
				{
					// Department
					r3::fields::String name;
					r3::relations::Relation2one<Owner> parent;
					// Owner
					r3::relations::Relation2n<Department> childs;
				};
				typedef boost::shared_ptr<Department> Department_ptr;
				
			}
			
			class Department
				: public CategoryBase<V1, Department, tuple::Department>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuple::Department Tuple;
				typedef tuple::Department_ptr Tuple_ptr;
				
				typedef V1 Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Department();
				V1 *schema();
				
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
				Department(V1 *s);
				
			protected:
				V1 *_schema;
				
			protected:
				std::string tupleFillKey(Tuple &tup);
				std::string tupleInsSql(Tuple &tup);
				std::string tupleUpdSql(Tuple &tup);
				std::string tupleSelSql(Tuple &tup);
				void tupleInsBind(Tuple &tup, pgc::Statement &stm);
				void tupleUpdBind(Tuple &tup, pgc::Statement &stm);
				
			};
			typedef boost::shared_ptr<Department> Department_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Department::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Owner>().get());
			}
			
			template <class Oper> void Department::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Department
				Department *c_Department = _schema->getCategory<Department>().get();
				o(this, c_Department, (r3::fields::String *)&tup.name, "name");
				//Owner
			}
			
			template <class Oper> void Department::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Department
				Department *c_Department = _schema->getCategory<Department>().get();
				o(this, c_Department, _schema->getCategory<Owner>().get(), (r3::relations::Relation2one<Owner>*)&tup.parent,	"parent",	(r3::relations::Relation2n<Department>*)NULL,	"childs",	rs_src);
				//Owner
				Owner *c_Owner = _schema->getCategory<Owner>().get();
				o(this, c_Owner, _schema->getCategory<Department>().get(), (r3::relations::Relation2n<Department>*)&tup.childs,	"childs",	(r3::relations::Relation2one<Owner>*)NULL,	"parent",	rs_dst);
			}
			
			template <class Oper> void Department::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Department
				//Owner
			}
			
			inline Department::Department(V1 *s)
				: CategoryBase<V1, Department, tuple::Department>("Department")
				, _schema(s)
			{
			}
			
			inline Department::~Department()
			{
			}
			
			inline V1 *Department::schema()
			{
				return _schema;
			}
			
			inline void Department::ins(Department::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Department::ins(Department::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Department::upd(Department::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Department::upd(Department::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Department::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Department::del(Department::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Department::del(Department::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Department::Tuple_ptr  Department::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Department::Tuple_ptr Department::sel(Department::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Department::tupleFillKey(Tuple &tup)
			{
				std::string res(1, '0');
				
				if(tup.name.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				return res;
			}
			inline std::string  Department::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
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
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  Department::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Department::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Department::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.name.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.name.value(), idx + 1);
					idx++;
				}
			}
			inline void  Department::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
