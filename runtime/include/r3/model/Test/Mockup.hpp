// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Mockup_hpp_
#define _r3_model_Test_Mockup_hpp_

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
				struct Mockup
						: public TupleBase<Mockup>
				{
					// Document
					r3::fields::Date creation;
					r3::fields::File file;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<s_Test::ServicePart> servicePart;
					// Mockup
					r3::fields::Audio audio;
					r3::fields::Image image;
					r3::fields::Video video;
					r3::relations::Relation2one<s_Test::WebSite> webSite;
					
					static const size_t _fieldsAmount = 6;
					static const size_t _relationsAmount = 2;
					
				};
				typedef boost::shared_ptr<Mockup> Mockup_ptr;
				
			}
			
			class Mockup
				: public CategoryBase<Test, Mockup, tuples::Mockup>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Mockup Tuple;
				typedef tuples::Mockup_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Mockup();
				Test *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Mockup(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Mockup> Mockup_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Mockup::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Document>().get());
			}
			
			template <class Oper> void Mockup::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, &tup.creation, "creation");
				o(this, c_Document, &tup.file, "file");
				o(this, c_Document, &tup.lastModified, "lastModified");
				//Mockup
				Mockup *c_Mockup = _schema->getCategory<Mockup>().get();
				o(this, c_Mockup, &tup.audio, "audio");
				o(this, c_Mockup, &tup.image, "image");
				o(this, c_Mockup, &tup.video, "video");
			}
			
			template <class Oper> void Mockup::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), &tup.servicePart,	"servicePart",	(r3::relations::Relation2n<s_Test::Document>*)NULL,	"documents",	rs_dst);
				//Mockup
				Mockup *c_Mockup = _schema->getCategory<Mockup>().get();
				o(this, c_Mockup, _schema->getCategory<WebSite>().get(), &tup.webSite,	"webSite",	(r3::relations::Relation2n<s_Test::Mockup>*)NULL,	"mockups",	rs_src);
			}
			
			template <class Oper> void Mockup::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Document
				//Mockup
			}
			
			inline Mockup::Mockup(Test *s)
				: CategoryBase<Test, Mockup, tuples::Mockup>("Mockup")
				, _schema(s)
			{
			}
			
			inline Mockup::~Mockup()
			{
			}
			
			inline Test *Mockup::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
