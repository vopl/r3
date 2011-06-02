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
		
			namespace tuples
			{
				struct Department
						: public TupleBase<Department>
				{
					// Department
					r3::fields::String name;
					r3::relations::Relation2one<Owner> parent;
					// Owner
					r3::relations::Relation2n<Department> childs;
					
					static const size_t _fieldsAmount = 1;
					static const size_t _relationsAmount = 2;
					
				};
				typedef boost::shared_ptr<Department> Department_ptr;
				
			}
			
			class Department
				: public CategoryBase<V1, Department, tuples::Department>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Department Tuple;
				typedef tuples::Department_ptr Tuple_ptr;
				
				typedef V1 Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Department();
				V1 *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Department(V1 *s);
				
			protected:
				V1 *_schema;
				
			};
			typedef boost::shared_ptr<Department> Department_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Department::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Owner>().get());
			}
			
			template <class Oper> void Department::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Department
				Department *c_Department = _schema->getCategory<Department>().get();
				o(this, c_Department, &tup.name, "name");
				//Owner
			}
			
			template <class Oper> void Department::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Department
				Department *c_Department = _schema->getCategory<Department>().get();
				o(this, c_Department, _schema->getCategory<Owner>().get(), (r3::relations::Relation2one<Owner>*)&tup.parent,	"parent",	(r3::relations::Relation2n<Department>*)NULL,	"childs",	rs_src);
				//Owner
				Owner *c_Owner = _schema->getCategory<Owner>().get();
				o(this, c_Owner, _schema->getCategory<Department>().get(), (r3::relations::Relation2n<Department>*)&tup.childs,	"childs",	(r3::relations::Relation2one<Owner>*)NULL,	"parent",	rs_dst);
			}
			
			template <class Oper> void Department::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Department
				//Owner
			}
			
			inline Department::Department(V1 *s)
				: CategoryBase<V1, Department, tuples::Department>("Department")
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
			
		}
	}
}

#endif
