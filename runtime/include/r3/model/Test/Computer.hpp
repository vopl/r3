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
				
			public:
			
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
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Computer();
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
			
			template <class Oper> void Computer::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Computer
				Computer *c_Computer = _schema->getCategory<Computer>().get();
				o(this, c_Computer, (r3::fields::DateTimeInterval *)&tup.equipmentInterval, "equipmentInterval");
				o(this, c_Computer, (r3::fields::Timestamp *)&tup.equipmentStamp, "equipmentStamp");
				o(this, c_Computer, (r3::fields::Bool *)&tup.mobile, "mobile");
				o(this, c_Computer, (r3::fields::String *)&tup.model, "model");
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_Stock, (r3::fields::Date *)&tup.incomingDate, "incomingDate");
				o(this, c_Stock, (r3::fields::String *)&tup.inventoryNumber, "inventoryNumber");
				o(this, c_Stock, (r3::fields::Enum<Stock::DomainsecurityStatus>*)&tup.securityStatus, "securityStatus");
			}
			
			template <class Oper> void Computer::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Computer
				//Stock
				Stock *c_Stock = _schema->getCategory<Stock>().get();
				o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n<Service>*)&tup.services,	"services",	(r3::relations::Relation2n<Stock>*)NULL,	"stocks",	rs_dst);
			}
			
			template <class Oper> void Computer::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Computer
				//Stock
			}
			
			inline Computer::Computer(Test *s)
				: CategoryBase<Computer>("Computer")
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
			
			inline void Computer::ins(Computer::Tuple &tup)
			{
				return CategoryBase<Computer>::ins(this, tup);
			}
			
			inline void Computer::ins(Computer::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Computer::upd(Computer::Tuple &tup)
			{
				return CategoryBase<Computer>::upd(this, tup);
			}
			
			inline void Computer::upd(Computer::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Computer::del(const fields::Id &id)
			{
				return CategoryBase<Computer>::del(this, id);
			}
			
			inline void Computer::del(Computer::Tuple &tup)
			{
				return CategoryBase<Computer>::del(this, tup);
			}
			
			inline void Computer::del(Computer::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Computer::Tuple_ptr  Computer::sel(const fields::Id &id)
			{
				return CategoryBase<Computer>::sel(this, id);
			}
			
			inline Computer::Tuple_ptr Computer::sel(Computer::Tuple_ptr tup)
			{
				return CategoryBase<Computer>::sel(this, tup);
			}
			
		}
	}
}

#endif
