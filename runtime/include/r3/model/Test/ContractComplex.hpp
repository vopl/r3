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
		
			class ContractComplex
				: public CategoryBase<ContractComplex>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public Contract::Tuple
				{
					r3::fields::Date date;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~ContractComplex();
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
			
			template <class Oper> void ContractComplex::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Contract
				Contract *c_Contract = _schema->getCategory<Contract>().get();
				o(this, c_Contract, (r3::fields::Int32 *)&tup.param1, "param1");
				o(this, c_Contract, (r3::fields::Int64 *)&tup.param2, "param2");
				o(this, c_Contract, (r3::fields::Int8 *)&tup.param3, "param3");
				o(this, c_Contract, (r3::fields::Real64 *)&tup.param4, "param4");
				//ContractComplex
				ContractComplex *c_ContractComplex = _schema->getCategory<ContractComplex>().get();
				o(this, c_ContractComplex, (r3::fields::Date *)&tup.date, "date");
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)&tup.creation, "creation");
				o(this, c_Document, (r3::fields::File *)&tup.file, "file");
				o(this, c_Document, (r3::fields::Timestamp *)&tup.lastModified, "lastModified");
			}
			
			template <class Oper> void ContractComplex::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Contract
				//ContractComplex
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
			}
			
			template <class Oper> void ContractComplex::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Contract
				//ContractComplex
				//Document
			}
			
			inline ContractComplex::ContractComplex(Test *s)
				: CategoryBase<ContractComplex>("ContractComplex")
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
			
			inline void ContractComplex::ins(ContractComplex::Tuple &tup)
			{
				return CategoryBase<ContractComplex>::ins(this, tup);
			}
			
			inline void ContractComplex::ins(ContractComplex::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void ContractComplex::upd(ContractComplex::Tuple &tup)
			{
				return CategoryBase<ContractComplex>::upd(this, tup);
			}
			
			inline void ContractComplex::upd(ContractComplex::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void ContractComplex::del(const fields::Id &id)
			{
				return CategoryBase<ContractComplex>::del(this, id);
			}
			
			inline void ContractComplex::del(ContractComplex::Tuple &tup)
			{
				return CategoryBase<ContractComplex>::del(this, tup);
			}
			
			inline void ContractComplex::del(ContractComplex::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline ContractComplex::Tuple_ptr  ContractComplex::sel(const fields::Id &id)
			{
				return CategoryBase<ContractComplex>::sel(this, id);
			}
			
			inline ContractComplex::Tuple_ptr ContractComplex::sel(ContractComplex::Tuple_ptr tup)
			{
				return CategoryBase<ContractComplex>::sel(this, tup);
			}
			
		}
	}
}

#endif
