// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_Owner_hpp_
#define _r3_model_V1_Owner_hpp_

#include "r3/categoryBase.hpp"

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
				struct Owner
						: public TupleBase<Owner>
				{
					// Owner
					r3::relations::Relation2n<s_V1::Department> childs;
					
					static const size_t _fieldsAmount = 0;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<Owner> Owner_ptr;
				
			}
			
			class Owner
				: public CategoryBase<V1, Owner, tuples::Owner>
			{
			
			public:
				static const bool isAbstract = true;
				
				typedef tuples::Owner Tuple;
				typedef tuples::Owner_ptr Tuple_ptr;
				
				typedef V1 Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Owner();
				V1 *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Owner(V1 *s);
				
			protected:
				V1 *_schema;
				
			};
			typedef boost::shared_ptr<Owner> Owner_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Owner::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Owner::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Owner
			}
			
			template <class Oper> void Owner::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Owner
				Owner *c_Owner = _schema->getCategory<Owner>().get();
				o(this, c_Owner, _schema->getCategory<Department>().get(), &tup.childs,	"childs",	(r3::relations::Relation2one<s_V1::Owner>*)NULL,	"parent",	rs_dst);
			}
			
			template <class Oper> void Owner::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Owner
			}
			
			inline Owner::Owner(V1 *s)
				: CategoryBase<V1, Owner, tuples::Owner>("Owner")
				, _schema(s)
			{
			}
			
			inline Owner::~Owner()
			{
			}
			
			inline V1 *Owner::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
