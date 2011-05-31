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
		
			namespace tuples
			{
				struct Document
						: public TupleBase<Document>
				{
					// Document
					r3::fields::Date creation;
					r3::fields::File file;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<ServicePart> servicePart;
					
					static const size_t _fieldsAmount = 3;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<Document> Document_ptr;
				
			}
			
			class Document
				: public CategoryBase<Test, Document, tuples::Document>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Document Tuple;
				typedef tuples::Document_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Document();
				Test *schema();
				
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
			
			template <class Oper> void Document::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)&tup.creation, "creation");
				o(this, c_Document, (r3::fields::File *)&tup.file, "file");
				o(this, c_Document, (r3::fields::Timestamp *)&tup.lastModified, "lastModified");
			}
			
			template <class Oper> void Document::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
			}
			
			template <class Oper> void Document::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Document
			}
			
			inline Document::Document(Test *s)
				: CategoryBase<Test, Document, tuples::Document>("Document")
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
