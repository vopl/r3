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
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Owner();
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
			
			template <class Oper> void Owner::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Owner
			}
			
			template <class Oper> void Owner::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Owner
				Owner *c_Owner = _schema->getCategory<Owner>().get();
				o(this, c_Owner, _schema->getCategory<Department>().get(), (r3::relations::Relation2n<Department>*)&tup.childs,	"childs",	(r3::relations::Relation2one<Owner>*)NULL,	"parent",	rs_dst);
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
			
			inline void Owner::ins(Owner::Tuple &tup)
			{
				return CategoryBase<Owner>::ins(this, tup);
			}
			
			inline void Owner::ins(Owner::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Owner::upd(Owner::Tuple &tup)
			{
				return CategoryBase<Owner>::upd(this, tup);
			}
			
			inline void Owner::upd(Owner::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Owner::del(const fields::Id &id)
			{
				return CategoryBase<Owner>::del(this, id);
			}
			
			inline void Owner::del(Owner::Tuple &tup)
			{
				return CategoryBase<Owner>::del(this, tup);
			}
			
			inline void Owner::del(Owner::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Owner::Tuple_ptr  Owner::sel(const fields::Id &id)
			{
				return CategoryBase<Owner>::sel(this, id);
			}
			
			inline Owner::Tuple_ptr Owner::sel(Owner::Tuple_ptr tup)
			{
				return CategoryBase<Owner>::sel(this, tup);
			}
			
		}
	}
}

#endif
