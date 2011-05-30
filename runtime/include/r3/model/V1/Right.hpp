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
		
			class Right
				: public CategoryBase<Right>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
				struct Domainvalue
				{
					static const size_t amount = 3;
					static const char *values[amount];
				};
				
				
			public:
				struct Tuple
						: public CategoryBase<Right>::Tuple
				{
					r3::fields::String name;
					r3::fields::Enum<Right::Domainvalue> value;
					r3::relations::Relation2n<HasRights> rights;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Right();
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
			
			template <class Oper> void Right::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Right
				Right *c_Right = _schema->getCategory<Right>().get();
				o(this, c_Right, (r3::fields::String *)&tup.name, "name");
				o(this, c_Right, (r3::fields::Enum<Right::Domainvalue>*)&tup.value, "value");
			}
			
			template <class Oper> void Right::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Right
				Right *c_Right = _schema->getCategory<Right>().get();
				o(this, c_Right, _schema->getCategory<HasRights>().get(), (r3::relations::Relation2n<HasRights>*)&tup.rights,	"rights",	(r3::relations::Relation2n<Right>*)NULL,	"owners",	rs_src);
			}
			
			template <class Oper> void Right::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Right
			}
			
			inline Right::Right(V1 *s)
				: CategoryBase<Right>("Right")
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
			
			inline void Right::ins(Right::Tuple &tup)
			{
				return CategoryBase<Right>::ins(this, tup);
			}
			
			inline void Right::ins(Right::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Right::upd(Right::Tuple &tup)
			{
				return CategoryBase<Right>::upd(this, tup);
			}
			
			inline void Right::upd(Right::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Right::del(const fields::Id &id)
			{
				return CategoryBase<Right>::del(this, id);
			}
			
			inline void Right::del(Right::Tuple &tup)
			{
				return CategoryBase<Right>::del(this, tup);
			}
			
			inline void Right::del(Right::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Right::Tuple_ptr  Right::sel(const fields::Id &id)
			{
				return CategoryBase<Right>::sel(this, id);
			}
			
			inline Right::Tuple_ptr Right::sel(Right::Tuple_ptr tup)
			{
				return CategoryBase<Right>::sel(this, tup);
			}
			
		}
	}
}

#endif
