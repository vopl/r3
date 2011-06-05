// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_ContractComplex_hpp_
#define _r3_model_Test_ContractComplex_hpp_

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
		
			namespace tuples
			{
				struct ContractComplex
						: public TupleBase<ContractComplex>
				{
					// Contract
					r3::fields::Int32 param1;
					r3::fields::Int64 param2;
					r3::fields::Int8 param3;
					r3::fields::Real64 param4;
					// ContractComplex
					r3::fields::Date date;
					// Document
					r3::fields::Date creation;
					r3::fields::File file;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<s_Test::ServicePart> servicePart;
					
					static const size_t _fieldsAmount = 8;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<ContractComplex> ContractComplex_ptr;
				
			}
			
			class ContractComplex
				: public CategoryBase<Test, ContractComplex, tuples::ContractComplex>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::ContractComplex Tuple;
				typedef tuples::ContractComplex_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~ContractComplex();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				ContractComplex(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<ContractComplex> ContractComplex_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void ContractComplex::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Contract>().get());
			}
			
			template <class Oper> void ContractComplex::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Contract
				Contract *c_Contract = _schema->getCategory<Contract>().get();
				o(this, c_Contract, &tup.param1, "param1");
				o(this, c_Contract, &tup.param2, "param2");
				o(this, c_Contract, &tup.param3, "param3");
				o(this, c_Contract, &tup.param4, "param4");
				//ContractComplex
				ContractComplex *c_ContractComplex = _schema->getCategory<ContractComplex>().get();
				o(this, c_ContractComplex, &tup.date, "date");
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, &tup.creation, "creation");
				o(this, c_Document, &tup.file, "file");
				o(this, c_Document, &tup.lastModified, "lastModified");
			}
			
			template <class Oper> void ContractComplex::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Contract
				//ContractComplex
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), &tup.servicePart,	"servicePart",	(r3::relations::Relation2n<s_Test::Document>*)NULL,	"documents",	rs_dst);
			}
			
			template <class Oper> void ContractComplex::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Contract
				//ContractComplex
				//Document
			}
			
			inline ContractComplex::ContractComplex(Test *s)
				: CategoryBase<Test, ContractComplex, tuples::ContractComplex>("ContractComplex")
				, _schema(s)
			{
			}
			
			inline ContractComplex::~ContractComplex()
			{
			}
			
			inline Test *ContractComplex::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
