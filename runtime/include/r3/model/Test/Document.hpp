// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Document_hpp_
#define _r3_model_Test_Document_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			//deriveds
			class Contract;
			typedef boost::shared_ptr<Contract> Contract_ptr;
			class ContractComplex;
			typedef boost::shared_ptr<ContractComplex> ContractComplex_ptr;
			class ContractSimple;
			typedef boost::shared_ptr<ContractSimple> ContractSimple_ptr;
			class Letter;
			typedef boost::shared_ptr<Letter> Letter_ptr;
			class Mockup;
			typedef boost::shared_ptr<Mockup> Mockup_ptr;
			
			class Document
				: public CategoryBase<Document>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, (r3::fields::Date *)NULL, "Creation");
					o(this, c_Document, (r3::fields::Timestamp *)NULL, "LastModified");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one *)NULL,	"servicePart",	(r3::relations::Relation2n *)NULL,	"documents",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Document
				}
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Document(Schema *s)
					: CategoryBase<Document>("Document")
					, _schema(s)
				{
				}
				
				~Document()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Document> Document_ptr;
		}
	}
}

#endif
