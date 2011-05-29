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
				
				struct DomainConstraints
				{
					static const size_t amount = 4;
					static const char *values[amount];
				};
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<Stock>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Furniture
					Furniture *c_Furniture = _schema->getCategory<Furniture>().get();
					o(this, c_Furniture, (r3::fields::Set<Furniture::DomainConstraints>*)NULL, "Constraints");
					o(this, c_Furniture, (r3::fields::Int16 *)NULL, "Depth");
					o(this, c_Furniture, (r3::fields::Int16 *)NULL, "Height");
					o(this, c_Furniture, (r3::fields::Real32 *)NULL, "Weight");
					o(this, c_Furniture, (r3::fields::Int16 *)NULL, "Width");
					//Stock
					Stock *c_Stock = _schema->getCategory<Stock>().get();
					o(this, c_Stock, (r3::fields::Money *)NULL, "Cost");
					o(this, c_Stock, (r3::fields::Date *)NULL, "IncomingDate");
					o(this, c_Stock, (r3::fields::String *)NULL, "InventoryNumber");
					o(this, c_Stock, (r3::fields::Enum<Stock::DomainSecurityStatus>*)NULL, "SecurityStatus");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Furniture
					//Stock
					Stock *c_Stock = _schema->getCategory<Stock>().get();
					o(this, c_Stock, _schema->getCategory<Service>().get(), (r3::relations::Relation2n *)NULL,	"services",	(r3::relations::Relation2n *)NULL,	"stocks",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Furniture
					//Stock
				}
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Furniture(Schema *s)
					: CategoryBase<Furniture>("Furniture")
					, _schema(s)
				{
				}
				
				~Furniture()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Furniture> Furniture_ptr;
		}
	}
}

#endif
