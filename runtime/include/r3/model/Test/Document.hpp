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
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, (r3::fields::Date *)NULL, "creation");
					o(this, c_Document, (r3::fields::Timestamp *)NULL, "lastModified");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Document
					Document *c_Document = _schema->getCategory<Document>().get();
					o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Document
				}
				
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
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Document(Schema *s)
					: CategoryBase<Document>("Document")
					, _schema(s)
				{
				}
				
				~Document()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Document> Document_ptr;
		}
	}
}

#endif
