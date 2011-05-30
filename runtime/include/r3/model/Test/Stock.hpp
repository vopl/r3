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
		
			class Stock
				: public CategoryBase<Stock>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
				struct DomainsecurityStatus
				{
					static const size_t amount = 3;
					static const char *values[amount];
				};
				
				
			public:
				struct Tuple
						: public CategoryBase<Stock>::Tuple
				{
					r3::fields::Money cost;
					r3::fields::Date incomingDate;
					r3::fields::String inventoryNumber;
					r3::fields::Enum<Stock::DomainsecurityStatus> securityStatus;
					r3::relations::Relation2n<Service> services;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
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
			
			template <class Oper> void Stock::enumFieldsFromBasesAndSelf(Oper o)
			{
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, (r3::fields::Money *)NULL, "cost");
				o(this, c_Stock, (r3::fields::Date *)NULL, "incomingDate");
				o(this, c_Stock, (r3::fields::String *)NULL, "inventoryNumber");
				o(this, c_Stock, (r3::fields::Enum<Stock::DomainsecurityStatus>*)NULL, "securityStatus");
			}
			
			template <class Oper> void Stock::enumRelationsFromBasesAndSelf(Oper o)
			{
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)NULL,	"services",	(r3::relations::Relation2n<Stock>*)NULL,	"stocks",	rs_dst);
			}
			
			template <class Oper> void Stock::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Stock
			}
			
			inline Stock::Stock(Test *s)
				: CategoryBase<Stock>("Stock")
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
