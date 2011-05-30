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
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Right();
				V1 *schema();
				
				void ins(Tuple &tup);
				void ins(Tuple_ptr tup);
				
				void upd(Tuple &tup);
				void upd(Tuple_ptr tup);
				
				void del(const boost::int64_t &id);
				void del(Tuple &tup);
				void del(Tuple_ptr tup);
				
				Tuple_ptr sel(const boost::int64_t &id);
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
			
			template <class Oper> void Right::enumFieldsFromBasesAndSelf(Oper o)
			{
				//Right
				Right *c_Right = _schema->getCategory<Right>().get();
				o(this, c_Right, (r3::fields::String *)NULL, "name");
				o(this, c_Right, (r3::fields::Enum<Right::Domainvalue>*)NULL, "value");
			}
			
			template <class Oper> void Right::enumRelationsFromBasesAndSelf(Oper o)
			{
				//Right
				Right *c_Right = _schema->getCategory<Right>().get();
				o(this, c_Right, _schema->getCategory<HasRights>().get(), (r3::relations::Relation2n<HasRights>*)NULL,	"rights",	(r3::relations::Relation2n<Right>*)NULL,	"owners",	rs_src);
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
			
		}
	}
}

#endif
