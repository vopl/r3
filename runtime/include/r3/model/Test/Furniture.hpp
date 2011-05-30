// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Furniture_hpp_
#define _r3_model_Test_Furniture_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/Test/Stock.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			class Furniture
				: public CategoryBase<Furniture>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
				struct Domainconstraints
				{
					static const size_t amount = 4;
					static const char *values[amount];
				};
				
				
			public:
				struct Tuple
						: public Stock::Tuple
				{
					r3::fields::Set<Furniture::Domainconstraints> constraints;
					r3::fields::Int16 depth;
					r3::fields::Int16 height;
					r3::fields::Real32 weight;
					r3::fields::Int16 width;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				Furniture(Test *s);
				~Furniture();
				Test *schema();
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Furniture> Furniture_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Furniture::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Stock>().get());
			}
			
			template <class Oper> void Furniture::enumFieldsFromBasesAndSelf(Oper o)
			{
				//Furniture
				Furniture *c_Furniture = _schema->getCategory<Furniture>().get();
				o(this, c_Furniture, (r3::fields::Set<Furniture::Domainconstraints>*)NULL, "constraints");
				o(this, c_Furniture, (r3::fields::Int16 *)NULL, "depth");
				o(this, c_Furniture, (r3::fields::Int16 *)NULL, "height");
				o(this, c_Furniture, (r3::fields::Real32 *)NULL, "weight");
				o(this, c_Furniture, (r3::fields::Int16 *)NULL, "width");
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, (r3::fields::Money *)NULL, "cost");
				o(this, c_Stock, (r3::fields::Date *)NULL, "incomingDate");
				o(this, c_Stock, (r3::fields::String *)NULL, "inventoryNumber");
				o(this, c_Stock, (r3::fields::Enum<Stock::DomainsecurityStatus>*)NULL, "securityStatus");
			}
			
			template <class Oper> void Furniture::enumRelationsFromBasesAndSelf(Oper o)
			{
				//Furniture
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)NULL,	"services",	(r3::relations::Relation2n<Stock>*)NULL,	"stocks",	rs_dst);
			}
			
			template <class Oper> void Furniture::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Furniture
				//Stock
			}
			
			inline Furniture::Furniture(Test *s)
				: CategoryBase<Furniture>("Furniture")
				, _schema(s)
			{
			}
			
			inline Furniture::~Furniture()
			{
			}
			
			inline Test *Furniture::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
