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
		
			class Mockup
				: public CategoryBase<Mockup>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public Document::Tuple
				{
					r3::fields::Audio audio;
					r3::fields::Image image;
					r3::fields::Video video;
					r3::relations::Relation2one<WebSite> webSite;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Mockup();
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
			
			template <class Oper> void Mockup::enumFieldsFromBasesAndSelf(Oper o)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)NULL, "creation");
				o(this, c_Document, (r3::fields::File *)NULL, "file");
				o(this, c_Document, (r3::fields::Timestamp *)NULL, "lastModified");
				//Mockup
				Mockup *c_Mockup = _schema->getCategory<Mockup>().get();
				o(this, c_Mockup, (r3::fields::Audio *)NULL, "audio");
				o(this, c_Mockup, (r3::fields::Image *)NULL, "image");
				o(this, c_Mockup, (r3::fields::Video *)NULL, "video");
			}
			
			template <class Oper> void Mockup::enumRelationsFromBasesAndSelf(Oper o)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
				//Mockup
				Mockup *c_Mockup = _schema->getCategory<Mockup>().get();
				o(this, c_Mockup, _schema->getCategory<WebSite>().get(), (r3::relations::Relation2one<WebSite>*)NULL,	"webSite",	(r3::relations::Relation2n<Mockup>*)NULL,	"mockups",	rs_src);
			}
			
			template <class Oper> void Mockup::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Document
				//Mockup
			}
			
			inline Mockup::Mockup(Test *s)
				: CategoryBase<Mockup>("Mockup")
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
