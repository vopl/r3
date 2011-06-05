// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_HasRights_hpp_
#define _r3_model_V1_HasRights_hpp_

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
				struct HasRights
						: public TupleBase<HasRights>
				{
					// HasRights
					r3::fields::Bool attrInHasRights;
					r3::relations::Relation2n<s_V1::Right> owners;
					
					static const size_t _fieldsAmount = 1;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<HasRights> HasRights_ptr;
				
			}
			
			class HasRights
				: public CategoryBase<V1, HasRights, tuples::HasRights>
			{
			
			public:
				static const bool isAbstract = true;
				
				typedef tuples::HasRights Tuple;
				typedef tuples::HasRights_ptr Tuple_ptr;
				
				typedef V1 Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~HasRights();
				V1 *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				HasRights(V1 *s);
				
			protected:
				V1 *_schema;
				
			};
			typedef boost::shared_ptr<HasRights> HasRights_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void HasRights::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void HasRights::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, &tup.attrInHasRights, "attrInHasRights");
			}
			
			template <class Oper> void HasRights::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, _schema->getCategory<Right>().get(), &tup.owners,	"owners",	(r3::relations::Relation2n<s_V1::HasRights>*)NULL,	"rights",	rs_dst);
			}
			
			template <class Oper> void HasRights::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//HasRights
			}
			
			inline HasRights::HasRights(V1 *s)
				: CategoryBase<V1, HasRights, tuples::HasRights>("HasRights")
				, _schema(s)
			{
			}
			
			inline HasRights::~HasRights()
			{
			}
			
			inline V1 *HasRights::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
