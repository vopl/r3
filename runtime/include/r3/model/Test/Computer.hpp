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
		
			class Computer
				: public CategoryBase<Computer>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<Stock>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Computer
					Computer *c_Computer = _schema->getCategory<Computer>().get();
					o(this, c_Computer, (r3::fields::DateTimeInterval *)NULL, "equipmentInterval");
					o(this, c_Computer, (r3::fields::Timestamp *)NULL, "equipmentStamp");
					o(this, c_Computer, (r3::fields::Bool *)NULL, "mobile");
					o(this, c_Computer, (r3::fields::String *)NULL, "model");
					//Stock
					Stock *c_Stock = _schema->getCategory<Stock>().get();
					o(this, c_Stock, (r3::fields::Money *)NULL, "cost");
					o(this, c_Stock, (r3::fields::Date *)NULL, "incomingDate");
					o(this, c_Stock, (r3::fields::String *)NULL, "inventoryNumber");
					o(this, c_Stock, (r3::fields::Enum<Stock::DomainsecurityStatus>*)NULL, "securityStatus");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Computer
					//Stock
					Stock *c_Stock = _schema->getCategory<Stock>().get();
					o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)NULL,	"services",	(r3::relations::Relation2n<Stock>*)NULL,	"stocks",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Computer
					//Stock
				}
				
			public:
				struct Tuple
						: public Stock::Tuple
				{
					r3::fields::DateTimeInterval equipmentInterval;
					r3::fields::Timestamp equipmentStamp;
					r3::fields::Bool mobile;
					r3::fields::String model;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Computer(Schema *s)
					: CategoryBase<Computer>("Computer")
					, _schema(s)
				{
				}
				
				~Computer()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Computer> Computer_ptr;
		}
	}
}

#endif
