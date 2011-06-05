// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_Right_hpp_
#define _r3_model_V1_Right_hpp_

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
				struct DomainRightvalue
				{
					static const size_t amount = 3;
					static const char *values[amount];
				};
				
				struct Right
						: public TupleBase<Right>
				{
					// Right
					r3::fields::String name;
					r3::fields::Enum<DomainRightvalue> value;
					r3::relations::Relation2n<s_V1::HasRights> rights;
					
					static const size_t _fieldsAmount = 2;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<Right> Right_ptr;
				
			}
			
			class Right
				: public CategoryBase<V1, Right, tuples::Right>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Right Tuple;
				typedef tuples::Right_ptr Tuple_ptr;
				
				typedef V1 Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Right();
				V1 *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Right(V1 *s);
				
			protected:
				V1 *_schema;
				
			};
			typedef boost::shared_ptr<Right> Right_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Right::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Right::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Right
				Right *c_Right = _schema->getCategory<Right>().get();
				o(this, c_Right, &tup.name, "name");
				o(this, c_Right, &tup.value, "value");
			}
			
			template <class Oper> void Right::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Right
				Right *c_Right = _schema->getCategory<Right>().get();
				o(this, c_Right, _schema->getCategory<HasRights>().get(), &tup.rights,	"rights",	(r3::relations::Relation2n<s_V1::Right>*)NULL,	"owners",	rs_src);
			}
			
			template <class Oper> void Right::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Right
			}
			
			inline Right::Right(V1 *s)
				: CategoryBase<V1, Right, tuples::Right>("Right")
				, _schema(s)
			{
			}
			
			inline Right::~Right()
			{
			}
			
			inline V1 *Right::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
