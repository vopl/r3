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
		
			namespace tuples
			{
				struct DomainFurnitureconstraints
				{
					static const size_t amount = 4;
					static const char *values[amount];
				};
				
				struct Furniture
						: public TupleBase<Furniture>
				{
					// Furniture
					r3::fields::Set<DomainFurnitureconstraints> constraints;
					r3::fields::Int16 depth;
					r3::fields::Int16 height;
					r3::fields::Real32 weight;
					r3::fields::Int16 width;
					// Stock
					r3::fields::Money cost;
					r3::fields::Date incomingDate;
					r3::fields::String inventoryNumber;
					r3::fields::Enum<DomainStocksecurityStatus> securityStatus;
					r3::relations::Relation2n<Service> services;
					
					static const size_t _fieldsAmount = 9;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<Furniture> Furniture_ptr;
				
			}
			
			class Furniture
				: public CategoryBase<Test, Furniture, tuples::Furniture>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Furniture Tuple;
				typedef tuples::Furniture_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Furniture();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Furniture(Test *s);
				
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
			
			template <class Oper> void Furniture::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Furniture
				Furniture *c_Furniture = _schema->getCategory<Furniture>().get();
				o(this, c_Furniture, (r3::fields::Set<tuples::DomainFurnitureconstraints>*)&tup.constraints, "constraints");
				o(this, c_Furniture, (r3::fields::Int16 *)&tup.depth, "depth");
				o(this, c_Furniture, (r3::fields::Int16 *)&tup.height, "height");
				o(this, c_Furniture, (r3::fields::Real32 *)&tup.weight, "weight");
				o(this, c_Furniture, (r3::fields::Int16 *)&tup.width, "width");
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_Stock, (r3::fields::Date *)&tup.incomingDate, "incomingDate");
				o(this, c_Stock, (r3::fields::String *)&tup.inventoryNumber, "inventoryNumber");
				o(this, c_Stock, (r3::fields::Enum<tuples::DomainStocksecurityStatus>*)&tup.securityStatus, "securityStatus");
			}
			
			template <class Oper> void Furniture::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Furniture
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2n<Stock>*)NULL,	"stocks",	rs_dst);
			}
			
			template <class Oper> void Furniture::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Furniture
				//Stock
			}
			
			inline Furniture::Furniture(Test *s)
				: CategoryBase<Test, Furniture, tuples::Furniture>("Furniture")
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
