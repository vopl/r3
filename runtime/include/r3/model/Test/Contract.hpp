// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Contract_hpp_
#define _r3_model_Test_Contract_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/Test/Document.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			//deriveds
			class ContractComplex;
			typedef boost::shared_ptr<ContractComplex> ContractComplex_ptr;
			class ContractSimple;
			typedef boost::shared_ptr<ContractSimple> ContractSimple_ptr;
			
			class Contract
				: public CategoryBase<Contract>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<Document>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Contract
					Contract *c_Contract = _schema->getCategory<Contract>().get();
					o(this, c_Contract, (r3::fields::Int32 *)NULL, "Param1");
					o(this, c_Contract, (r3::fields::Int64 *)NULL, "Param2");
					o(this, c_Contract, (r3::fields::Int8 *)NULL, "Param3");
					o(this, c_Contract, (r3::fields::Real64 *)NULL, "Param4");
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, (r3::fields::Date *)NULL, "Creation");
					o(this, c_Document, (r3::fields::Timestamp *)NULL, "LastModified");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Contract
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one *)NULL,	"servicePart",	(r3::relations::Relation2n *)NULL,	"documents",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Contract
					//Document
				}
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Contract(Schema *s)
					: CategoryBase<Contract>("Contract")
					, _schema(s)
				{
				}
				
				~Contract()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Contract> Contract_ptr;
		}
	}
}

#endif
