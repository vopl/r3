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
		
			class Owner
				: public CategoryBase<Owner>
			{
			
			public:
				static const bool isAbstract = true;
				
			public:
			
			public:
				struct Tuple
						: public CategoryBase<Owner>::Tuple
				{
					r3::relations::Relation2n<Department> childs;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				Owner(V1 *s);
				~Owner();
				V1 *schema();
				
			protected:
				V1 *_schema;
				
			};
			typedef boost::shared_ptr<Owner> Owner_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Owner::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Owner::enumFieldsFromBasesAndSelf(Oper o)
			{
				//Owner
			}
			
			template <class Oper> void Owner::enumRelationsFromBasesAndSelf(Oper o)
			{
				//Owner
				Owner *c_Owner = _schema->getCategory<Owner>().get();
				o(this, c_Owner, _schema->getCategory<Department>().get(), (r3::relations::Relation2n<Department>*)NULL,	"childs",	(r3::relations::Relation2one<Owner>*)NULL,	"parent",	rs_dst);
			}
			
			template <class Oper> void Owner::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Owner
			}
			
			inline Owner::Owner(V1 *s)
				: CategoryBase<Owner>("Owner")
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
