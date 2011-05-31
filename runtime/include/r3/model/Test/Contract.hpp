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
		
			namespace tuples
			{
				struct Contract
						: public TupleBase<Contract>
				{
					// Contract
					r3::fields::Int32 param1;
					r3::fields::Int64 param2;
					r3::fields::Int8 param3;
					r3::fields::Real64 param4;
					// Document
					r3::fields::Date creation;
					r3::fields::File file;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<ServicePart> servicePart;
					
					static const size_t _fieldsAmount = 7;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<Contract> Contract_ptr;
				
			}
			
			class Contract
				: public CategoryBase<Test, Contract, tuples::Contract>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Contract Tuple;
				typedef tuples::Contract_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Contract();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Contract(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Contract> Contract_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Contract::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Document>().get());
			}
			
			template <class Oper> void Contract::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Contract
				Contract *c_Contract = _schema->getCategory<Contract>().get();
				o(this, c_Contract, (r3::fields::Int32 *)&tup.param1, "param1");
				o(this, c_Contract, (r3::fields::Int64 *)&tup.param2, "param2");
				o(this, c_Contract, (r3::fields::Int8 *)&tup.param3, "param3");
				o(this, c_Contract, (r3::fields::Real64 *)&tup.param4, "param4");
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)&tup.creation, "creation");
				o(this, c_Document, (r3::fields::File *)&tup.file, "file");
				o(this, c_Document, (r3::fields::Timestamp *)&tup.lastModified, "lastModified");
			}
			
			template <class Oper> void Contract::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Contract
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
			}
			
			template <class Oper> void Contract::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Contract
				//Document
			}
			
			inline Contract::Contract(Test *s)
				: CategoryBase<Test, Contract, tuples::Contract>("Contract")
				, _schema(s)
			{
			}
			
			inline Contract::~Contract()
			{
			}
			
			inline Test *Contract::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
