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
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Stock();
				Test *schema();
				
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
			
			template <class Oper> void Stock::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_Stock, (r3::fields::Date *)&tup.incomingDate, "incomingDate");
				o(this, c_Stock, (r3::fields::String *)&tup.inventoryNumber, "inventoryNumber");
				o(this, c_Stock, (r3::fields::Enum<Stock::DomainsecurityStatus>*)&tup.securityStatus, "securityStatus");
			}
			
			template <class Oper> void Stock::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2n<Stock>*)NULL,	"stocks",	rs_dst);
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
			
			inline void Stock::ins(Stock::Tuple &tup)
			{
				return CategoryBase<Stock>::ins(this, tup);
			}
			
			inline void Stock::ins(Stock::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Stock::upd(Stock::Tuple &tup)
			{
				return CategoryBase<Stock>::upd(this, tup);
			}
			
			inline void Stock::upd(Stock::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Stock::del(const fields::Id &id)
			{
				return CategoryBase<Stock>::del(this, id);
			}
			
			inline void Stock::del(Stock::Tuple &tup)
			{
				return CategoryBase<Stock>::del(this, tup);
			}
			
			inline void Stock::del(Stock::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Stock::Tuple_ptr  Stock::sel(const fields::Id &id)
			{
				return CategoryBase<Stock>::sel(this, id);
			}
			
			inline Stock::Tuple_ptr Stock::sel(Stock::Tuple_ptr tup)
			{
				return CategoryBase<Stock>::sel(this, tup);
			}
			
		}
	}
}

#endif
