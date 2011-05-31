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
					// Document
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
				
			protected:
				std::string tupleFillKey(Tuple &tup);
				std::string tupleInsSql(Tuple &tup);
				std::string tupleUpdSql(Tuple &tup);
				std::string tupleSelSql(Tuple &tup);
				void tupleInsBind(Tuple &tup, pgc::Statement &stm);
				void tupleUpdBind(Tuple &tup, pgc::Statement &stm);
				
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
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Document::ins(Document::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Document::upd(Document::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Document::upd(Document::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Document::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Document::del(Document::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Document::del(Document::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Document::Tuple_ptr  Document::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Document::Tuple_ptr Document::sel(Document::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Document::tupleFillKey(Tuple &tup)
			{
				std::string res(3, '0');
				
				if(tup.creation.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.file.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.lastModified.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				return res;
			}
			inline std::string  Document::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
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
				
				res = "INSERT INTO " + db_sname() + "(" + res;
				res += ") VALUES (" + vals + ")";
				return res;
			}
			inline std::string  Document::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Document::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Document::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
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
				
				if(tup.lastModified.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.lastModified.value(), idx + 1);
					idx++;
				}
			}
			inline void  Document::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
