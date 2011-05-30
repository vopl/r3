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
					r3::fields::File file;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<ServicePart> servicePart;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Document();
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
			
			template <class Oper> void Document::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)&tup.creation, "creation");
				o(this, c_Document, (r3::fields::File *)&tup.file, "file");
				o(this, c_Document, (r3::fields::Timestamp *)&tup.lastModified, "lastModified");
			}
			
			template <class Oper> void Document::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
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
			
			inline void Document::ins(Document::Tuple &tup)
			{
				return CategoryBase<Document>::ins(this, tup);
			}
			
			inline void Document::ins(Document::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Document::upd(Document::Tuple &tup)
			{
				return CategoryBase<Document>::upd(this, tup);
			}
			
			inline void Document::upd(Document::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Document::del(const fields::Id &id)
			{
				return CategoryBase<Document>::del(this, id);
			}
			
			inline void Document::del(Document::Tuple &tup)
			{
				return CategoryBase<Document>::del(this, tup);
			}
			
			inline void Document::del(Document::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Document::Tuple_ptr  Document::sel(const fields::Id &id)
			{
				return CategoryBase<Document>::sel(this, id);
			}
			
			inline Document::Tuple_ptr Document::sel(Document::Tuple_ptr tup)
			{
				return CategoryBase<Document>::sel(this, tup);
			}
			
		}
	}
}

#endif
