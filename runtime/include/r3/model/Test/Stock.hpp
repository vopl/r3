// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Stock_hpp_
#define _r3_model_Test_Stock_hpp_

#include "r3/categoryBase.hpp"

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
				struct DomainStocksecurityStatus
				{
					static const size_t amount = 3;
					static const char *values[amount];
				};
				
				struct Stock
						: public TupleBase<Stock>
				{
					// Stock
					r3::fields::Money cost;
					r3::fields::Date incomingDate;
					r3::fields::String inventoryNumber;
					r3::fields::Enum<DomainStocksecurityStatus> securityStatus;
					r3::relations::Relation2n<s_Test::Service> services;
					
					static const size_t _fieldsAmount = 4;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<Stock> Stock_ptr;
				
			}
			
			class Stock
				: public CategoryBase<Test, Stock, tuples::Stock>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Stock Tuple;
				typedef tuples::Stock_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Stock();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Stock(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Stock> Stock_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Stock::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Stock::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, &tup.cost, "cost");
				o(this, c_Stock, &tup.incomingDate, "incomingDate");
				o(this, c_Stock, &tup.inventoryNumber, "inventoryNumber");
				o(this, c_Stock, &tup.securityStatus, "securityStatus");
			}
			
			template <class Oper> void Stock::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), &tup.services,	"services",	(r3::relations::Relation2n<s_Test::Stock>*)NULL,	"stocks",	rs_dst);
			}
			
			template <class Oper> void Stock::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Stock
			}
			
			inline Stock::Stock(Test *s)
				: CategoryBase<Test, Stock, tuples::Stock>("Stock")
				, _schema(s)
			{
			}
			
			inline Stock::~Stock()
			{
			}
			
			inline Test *Stock::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
