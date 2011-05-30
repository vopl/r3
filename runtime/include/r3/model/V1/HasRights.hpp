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
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~HasRights();
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
			
			template <class Oper> void HasRights::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, (r3::fields::Bool *)&tup.attrInHasRights, "attrInHasRights");
			}
			
			template <class Oper> void HasRights::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, _schema->getCategory<Right>().get(), (r3::relations::Relation2n<Right>*)&tup.owners,	"owners",	(r3::relations::Relation2n<HasRights>*)NULL,	"rights",	rs_dst);
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
			
			inline void HasRights::ins(HasRights::Tuple &tup)
			{
				return CategoryBase<HasRights>::ins(this, tup);
			}
			
			inline void HasRights::ins(HasRights::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void HasRights::upd(HasRights::Tuple &tup)
			{
				return CategoryBase<HasRights>::upd(this, tup);
			}
			
			inline void HasRights::upd(HasRights::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void HasRights::del(const fields::Id &id)
			{
				return CategoryBase<HasRights>::del(this, id);
			}
			
			inline void HasRights::del(HasRights::Tuple &tup)
			{
				return CategoryBase<HasRights>::del(this, tup);
			}
			
			inline void HasRights::del(HasRights::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline HasRights::Tuple_ptr  HasRights::sel(const fields::Id &id)
			{
				return CategoryBase<HasRights>::sel(this, id);
			}
			
			inline HasRights::Tuple_ptr HasRights::sel(HasRights::Tuple_ptr tup)
			{
				return CategoryBase<HasRights>::sel(this, tup);
			}
			
		}
	}
}

#endif
