// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_ContractSimple_hpp_
#define _r3_model_Test_ContractSimple_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/Test/Contract.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			class ContractSimple
				: public CategoryBase<ContractSimple>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<Contract>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Contract
					Contract *c_Contract = _schema->getCategory<Contract>().get();
					o(this, c_Contract, (r3::fields::Int32 *)NULL, "param1");
					o(this, c_Contract, (r3::fields::Int64 *)NULL, "param2");
					o(this, c_Contract, (r3::fields::Int8 *)NULL, "param3");
					o(this, c_Contract, (r3::fields::Real64 *)NULL, "param4");
					//ContractSimple
					ContractSimple *c_ContractSimple = _schema->getCategory<ContractSimple>().get();
					o(this, c_ContractSimple, (r3::fields::Date *)NULL, "expiration");
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, (r3::fields::Date *)NULL, "creation");
					o(this, c_Document, (r3::fields::Timestamp *)NULL, "lastModified");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Contract
					//ContractSimple
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Contract
					//ContractSimple
					//Document
				}
				
			public:
				struct Tuple
						: public Contract::Tuple
				{
					r3::fields::Date expiration;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				ContractSimple(Schema *s)
					: CategoryBase<ContractSimple>("ContractSimple")
					, _schema(s)
				{
				}
				
				~ContractSimple()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<ContractSimple> ContractSimple_ptr;
		}
	}
}

#endif
