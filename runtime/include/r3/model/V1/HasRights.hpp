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
		
			class HasRights
				: public CategoryBase<HasRights>
			{
			
			public:
				static const bool isAbstract = true;
				
			public:
			
			public:
				struct Tuple
						: public CategoryBase<HasRights>::Tuple
				{
					r3::fields::Bool attrInHasRights;
					r3::relations::Relation2n<Right> owners;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
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
			
			template <class Oper> void HasRights::enumFieldsFromBasesAndSelf(Oper o)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, (r3::fields::Bool *)NULL, "attrInHasRights");
			}
			
			template <class Oper> void HasRights::enumRelationsFromBasesAndSelf(Oper o)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, _schema->getCategory<Right>().get(), (r3::relations::Relation2n<Right>*)NULL,	"owners",	(r3::relations::Relation2n<HasRights>*)NULL,	"rights",	rs_dst);
			}
			
			template <class Oper> void HasRights::enumIndicesFromBasesAndSelf(Oper o)
			{
				//HasRights
			}
			
			inline HasRights::HasRights(V1 *s)
				: CategoryBase<HasRights>("HasRights")
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
