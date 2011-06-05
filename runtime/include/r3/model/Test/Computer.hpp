// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Computer_hpp_
#define _r3_model_Test_Computer_hpp_

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
				struct Computer
						: public TupleBase<Computer>
				{
					// Computer
					r3::fields::DateTimeInterval equipmentInterval;
					r3::fields::Timestamp equipmentStamp;
					r3::fields::Bool mobile;
					r3::fields::String model;
					// Stock
					r3::fields::Money cost;
					r3::fields::Date incomingDate;
					r3::fields::String inventoryNumber;
					r3::fields::Enum<DomainStocksecurityStatus> securityStatus;
					r3::relations::Relation2n<s_Test::Service> services;
					
					static const size_t _fieldsAmount = 8;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<Computer> Computer_ptr;
				
			}
			
			class Computer
				: public CategoryBase<Test, Computer, tuples::Computer>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Computer Tuple;
				typedef tuples::Computer_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Computer();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Computer(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Computer> Computer_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Computer::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Stock>().get());
			}
			
			template <class Oper> void Computer::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Computer
				Computer *c_Computer = _schema->getCategory<Computer>().get();
				o(this, c_Computer, &tup.equipmentInterval, "equipmentInterval");
				o(this, c_Computer, &tup.equipmentStamp, "equipmentStamp");
				o(this, c_Computer, &tup.mobile, "mobile");
				o(this, c_Computer, &tup.model, "model");
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, &tup.cost, "cost");
				o(this, c_Stock, &tup.incomingDate, "incomingDate");
				o(this, c_Stock, &tup.inventoryNumber, "inventoryNumber");
				o(this, c_Stock, &tup.securityStatus, "securityStatus");
			}
			
			template <class Oper> void Computer::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Computer
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), &tup.services,	"services",	(r3::relations::Relation2n<s_Test::Stock>*)NULL,	"stocks",	rs_dst);
			}
			
			template <class Oper> void Computer::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Computer
				//Stock
			}
			
			inline Computer::Computer(Test *s)
				: CategoryBase<Test, Computer, tuples::Computer>("Computer")
				, _schema(s)
			{
			}
			
			inline Computer::~Computer()
			{
			}
			
			inline Test *Computer::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
