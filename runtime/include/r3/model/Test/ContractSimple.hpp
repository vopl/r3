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
		
			namespace tuples
			{
				struct ContractSimple
						: public TupleBase<ContractSimple>
				{
					// Contract
					r3::fields::Int32 param1;
					r3::fields::Int64 param2;
					r3::fields::Int8 param3;
					r3::fields::Real64 param4;
					// ContractSimple
					r3::fields::Date expiration;
					// Document
					r3::fields::Date creation;
					r3::fields::File file;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<ServicePart> servicePart;
					
					static const size_t _fieldsAmount = 8;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<ContractSimple> ContractSimple_ptr;
				
			}
			
			class ContractSimple
				: public CategoryBase<Test, ContractSimple, tuples::ContractSimple>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::ContractSimple Tuple;
				typedef tuples::ContractSimple_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~ContractSimple();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				ContractSimple(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<ContractSimple> ContractSimple_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void ContractSimple::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Contract>().get());
			}
			
			template <class Oper> void ContractSimple::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Contract
				Contract *c_Contract = _schema->getCategory<Contract>().get();
				o(this, c_Contract, (r3::fields::Int32 *)&tup.param1, "param1");
				o(this, c_Contract, (r3::fields::Int64 *)&tup.param2, "param2");
				o(this, c_Contract, (r3::fields::Int8 *)&tup.param3, "param3");
				o(this, c_Contract, (r3::fields::Real64 *)&tup.param4, "param4");
				//ContractSimple
				ContractSimple *c_ContractSimple = _schema->getCategory<ContractSimple>().get();
				o(this, c_ContractSimple, (r3::fields::Date *)&tup.expiration, "expiration");
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)&tup.creation, "creation");
				o(this, c_Document, (r3::fields::File *)&tup.file, "file");
				o(this, c_Document, (r3::fields::Timestamp *)&tup.lastModified, "lastModified");
			}
			
			template <class Oper> void ContractSimple::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Contract
				//ContractSimple
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
			}
			
			template <class Oper> void ContractSimple::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Contract
				//ContractSimple
				//Document
			}
			
			inline ContractSimple::ContractSimple(Test *s)
				: CategoryBase<Test, ContractSimple, tuples::ContractSimple>("ContractSimple")
				, _schema(s)
			{
			}
			
			inline ContractSimple::~ContractSimple()
			{
			}
			
			inline Test *ContractSimple::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
