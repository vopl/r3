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
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Mockup();
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
			
			template <class Oper> void Mockup::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)&tup.creation, "creation");
				o(this, c_Document, (r3::fields::File *)&tup.file, "file");
				o(this, c_Document, (r3::fields::Timestamp *)&tup.lastModified, "lastModified");
				//Mockup
				Mockup *c_Mockup = _schema->getCategory<Mockup>().get();
				o(this, c_Mockup, (r3::fields::Audio *)&tup.audio, "audio");
				o(this, c_Mockup, (r3::fields::Image *)&tup.image, "image");
				o(this, c_Mockup, (r3::fields::Video *)&tup.video, "video");
			}
			
			template <class Oper> void Mockup::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
				//Mockup
				Mockup *c_Mockup = _schema->getCategory<Mockup>().get();
				o(this, c_Mockup, _schema->getCategory<WebSite>().get(), (r3::relations::Relation2one<WebSite>*)&tup.webSite,	"webSite",	(r3::relations::Relation2n<Mockup>*)NULL,	"mockups",	rs_src);
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
			
			inline void Mockup::ins(Mockup::Tuple &tup)
			{
				return CategoryBase<Mockup>::ins(this, tup);
			}
			
			inline void Mockup::ins(Mockup::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Mockup::upd(Mockup::Tuple &tup)
			{
				return CategoryBase<Mockup>::upd(this, tup);
			}
			
			inline void Mockup::upd(Mockup::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Mockup::del(const fields::Id &id)
			{
				return CategoryBase<Mockup>::del(this, id);
			}
			
			inline void Mockup::del(Mockup::Tuple &tup)
			{
				return CategoryBase<Mockup>::del(this, tup);
			}
			
			inline void Mockup::del(Mockup::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Mockup::Tuple_ptr  Mockup::sel(const fields::Id &id)
			{
				return CategoryBase<Mockup>::sel(this, id);
			}
			
			inline Mockup::Tuple_ptr Mockup::sel(Mockup::Tuple_ptr tup)
			{
				return CategoryBase<Mockup>::sel(this, tup);
			}
			
		}
	}
}

#endif
