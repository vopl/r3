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
		
			class Contract
				: public CategoryBase<Contract>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public Document::Tuple
				{
					r3::fields::Int32 param1;
					r3::fields::Int64 param2;
					r3::fields::Int8 param3;
					r3::fields::Real64 param4;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Contract();
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
			
			template <class Oper> void Contract::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
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
			
			template <class Oper> void Contract::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Contract
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
			}
			
			template <class Oper> void Contract::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Contract
				//Document
			}
			
			inline Contract::Contract(Test *s)
				: CategoryBase<Contract>("Contract")
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
			
			inline void Contract::ins(Contract::Tuple &tup)
			{
				return CategoryBase<Contract>::ins(this, tup);
			}
			
			inline void Contract::ins(Contract::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Contract::upd(Contract::Tuple &tup)
			{
				return CategoryBase<Contract>::upd(this, tup);
			}
			
			inline void Contract::upd(Contract::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Contract::del(const fields::Id &id)
			{
				return CategoryBase<Contract>::del(this, id);
			}
			
			inline void Contract::del(Contract::Tuple &tup)
			{
				return CategoryBase<Contract>::del(this, tup);
			}
			
			inline void Contract::del(Contract::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Contract::Tuple_ptr  Contract::sel(const fields::Id &id)
			{
				return CategoryBase<Contract>::sel(this, id);
			}
			
			inline Contract::Tuple_ptr Contract::sel(Contract::Tuple_ptr tup)
			{
				return CategoryBase<Contract>::sel(this, tup);
			}
			
		}
	}
}

#endif
