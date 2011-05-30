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
		
			class Document
				: public CategoryBase<Document>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public CategoryBase<Document>::Tuple
				{
					r3::fields::Date creation;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<ServicePart> servicePart;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Document();
				Test *schema();
				
				void ins(Tuple &tup);
				void ins(Tuple_ptr tup);
				
				void upd(Tuple &tup);
				void upd(Tuple_ptr tup);
				
				void del(const boost::int64_t &id);
				void del(Tuple &tup);
				void del(Tuple_ptr tup);
				
				Tuple_ptr sel(const boost::int64_t &id);
				Tuple_ptr sel(Tuple_ptr tup);
				
			protected:
				template <class S> friend class SchemaBase;
				Document(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Document> Document_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Document::enumBasesFirst(Oper o)
			{
			}
			
			template <class Oper> void Document::enumFieldsFromBasesAndSelf(Oper o)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)NULL, "creation");
				o(this, c_Document, (r3::fields::Timestamp *)NULL, "lastModified");
			}
			
			template <class Oper> void Document::enumRelationsFromBasesAndSelf(Oper o)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
			}
			
			template <class Oper> void Document::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Document
			}
			
			inline Document::Document(Test *s)
				: CategoryBase<Document>("Document")
				, _schema(s)
			{
			}
			
			inline Document::~Document()
			{
			}
			
			inline Test *Document::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
