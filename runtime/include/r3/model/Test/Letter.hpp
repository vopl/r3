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
		
			class Letter
				: public CategoryBase<Letter>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<Document>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, (r3::fields::Date *)NULL, "creation");
					o(this, c_Document, (r3::fields::Timestamp *)NULL, "lastModified");
					//Letter
					Letter *c_Letter = _schema->getCategory<Letter>().get();
					o(this, c_Letter, (r3::fields::String *)NULL, "comment");
					o(this, c_Letter, (r3::fields::String *)NULL, "content");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
					//Letter
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Document
					//Letter
				}
				
			public:
				struct Tuple
						: public Document::Tuple
				{
					r3::fields::String comment;
					r3::fields::String content;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Letter(Schema *s)
					: CategoryBase<Letter>("Letter")
					, _schema(s)
				{
				}
				
				~Letter()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Letter> Letter_ptr;
		}
	}
}

#endif
