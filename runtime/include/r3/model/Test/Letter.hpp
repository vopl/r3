// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Letter_hpp_
#define _r3_model_Test_Letter_hpp_

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
				struct Letter
						: public TupleBase<Letter>
				{
					// Document
					r3::fields::Date creation;
					r3::fields::File file;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<ServicePart> servicePart;
					// Letter
					r3::fields::String comment;
					r3::fields::String content;
					
					static const size_t _fieldsAmount = 5;
					static const size_t _relationsAmount = 1;
					
				};
				typedef boost::shared_ptr<Letter> Letter_ptr;
				
			}
			
			class Letter
				: public CategoryBase<Test, Letter, tuples::Letter>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Letter Tuple;
				typedef tuples::Letter_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Letter();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Letter(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Letter> Letter_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Letter::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Document>().get());
			}
			
			template <class Oper> void Letter::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, &tup.creation, "creation");
				o(this, c_Document, &tup.file, "file");
				o(this, c_Document, &tup.lastModified, "lastModified");
				//Letter
				Letter *c_Letter = _schema->getCategory<Letter>().get();
				o(this, c_Letter, &tup.comment, "comment");
				o(this, c_Letter, &tup.content, "content");
			}
			
			template <class Oper> void Letter::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
				//Letter
			}
			
			template <class Oper> void Letter::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Document
				//Letter
			}
			
			inline Letter::Letter(Test *s)
				: CategoryBase<Test, Letter, tuples::Letter>("Letter")
				, _schema(s)
			{
			}
			
			inline Letter::~Letter()
			{
			}
			
			inline Test *Letter::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
