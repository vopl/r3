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
		
			namespace tuple
			{
				struct Mockup
						: public TupleBase<Mockup>
				{
					// Document
					r3::fields::Date creation;
					r3::fields::File file;
					r3::fields::Timestamp lastModified;
					r3::relations::Relation2one<ServicePart> servicePart;
					// Mockup
					r3::fields::Audio audio;
					r3::fields::Image image;
					r3::fields::Video video;
					r3::relations::Relation2one<WebSite> webSite;
				};
				typedef boost::shared_ptr<Mockup> Mockup_ptr;
				
			}
			
			class Mockup
				: public CategoryBase<Test, Mockup, tuple::Mockup>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuple::Mockup Tuple;
				typedef tuple::Mockup_ptr Tuple_ptr;
				
				typedef Test Schema;
				
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
				
			protected:
				std::string tupleFillKey(Tuple &tup);
				std::string tupleInsSql(Tuple &tup);
				std::string tupleUpdSql(Tuple &tup);
				std::string tupleSelSql(Tuple &tup);
				void tupleInsBind(Tuple &tup, pgc::Statement &stm);
				void tupleUpdBind(Tuple &tup, pgc::Statement &stm);
				
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
				: CategoryBase<Test, Mockup, tuple::Mockup>("Mockup")
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
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Mockup::ins(Mockup::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Mockup::upd(Mockup::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Mockup::upd(Mockup::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Mockup::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Mockup::del(Mockup::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Mockup::del(Mockup::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Mockup::Tuple_ptr  Mockup::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Mockup::Tuple_ptr Mockup::sel(Mockup::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Mockup::tupleFillKey(Tuple &tup)
			{
				std::string res(6, '0');
				
				if(tup.audio.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.creation.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.file.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.image.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				if(tup.lastModified.fvs() != fields::fvs_notset) {
					res[4] = '1';
				}
				
				if(tup.video.fvs() != fields::fvs_notset) {
					res[5] = '1';
				}
				
				return res;
			}
			inline std::string  Mockup::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
				if(tup.audio.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_audio_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.creation.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_creation_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.file.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_file_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.image.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_image_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.lastModified.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_lastModified_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.video.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_video_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  Mockup::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Mockup::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Mockup::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.audio.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.audio.value(), idx + 1);
					idx++;
				}
				
				if(tup.creation.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.creation.value(), idx + 1);
					idx++;
				}
				
				if(tup.file.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.file.value(), idx + 1);
					idx++;
				}
				
				if(tup.image.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.image.value(), idx + 1);
					idx++;
				}
				
				if(tup.lastModified.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.lastModified.value(), idx + 1);
					idx++;
				}
				
				if(tup.video.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.video.value(), idx + 1);
					idx++;
				}
			}
			inline void  Mockup::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
