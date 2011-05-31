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
		
			namespace tuple
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
				};
				typedef boost::shared_ptr<Letter> Letter_ptr;
				
			}
			
			class Letter
				: public CategoryBase<Test, Letter, tuple::Letter>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuple::Letter Tuple;
				typedef tuple::Letter_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Letter();
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
				Letter(Test *s);
				
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
			typedef boost::shared_ptr<Letter> Letter_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Letter::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<Document>().get());
			}
			
			template <class Oper> void Letter::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, (r3::fields::Date *)&tup.creation, "creation");
				o(this, c_Document, (r3::fields::File *)&tup.file, "file");
				o(this, c_Document, (r3::fields::Timestamp *)&tup.lastModified, "lastModified");
				//Letter
				Letter *c_Letter = _schema->getCategory<Letter>().get();
				o(this, c_Letter, (r3::fields::String *)&tup.comment, "comment");
				o(this, c_Letter, (r3::fields::String *)&tup.content, "content");
			}
			
			template <class Oper> void Letter::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Document
				Document *c_Document = _schema->getCategory<Document>().get();
				o(this, c_Document, _schema->getCategory<ServicePart>().get(), (r3::relations::Relation2one<ServicePart>*)&tup.servicePart,	"servicePart",	(r3::relations::Relation2n<Document>*)NULL,	"documents",	rs_dst);
				//Letter
			}
			
			template <class Oper> void Letter::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Document
				//Letter
			}
			
			inline Letter::Letter(Test *s)
				: CategoryBase<Test, Letter, tuple::Letter>("Letter")
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
			
			inline void Letter::ins(Letter::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_ins_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleInsSql(tup));
				}
				
				tupleInsBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Letter::ins(Letter::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Letter::upd(Letter::Tuple &tup)
			{
				pgc::Statement stm_ = stm(tupleFillKey(tup) + "_upd_tuple");
				
				if(stm_.empty()) {
					stm_.sql(tupleUpdSql(tup));
				}
				
				tupleUpdBind(tup, stm_);
				stm_.exec().throwIfError();
			}
			
			inline void Letter::upd(Letter::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Letter::del(const fields::Id &id)
			{
				pgc::Statement stm_ = stm("del_id");
				
				if(stm_.empty()) {
					stm_.sql("DELETE FROM " + db_sname() + " WHERE id=$1::INT8");
				}
				
				stm_.bind(id.value());
				stm_.exec().throwIfError();
			}
			
			inline void Letter::del(Letter::Tuple &tup)
			{
				del(tup.id);
				tup.id.value() = 0;
			}
			
			inline void Letter::del(Letter::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Letter::Tuple_ptr  Letter::sel(const fields::Id &id)
			{
				Tuple_ptr tup(new Tuple);
				tup->id = id;
				return sel(tup);
			}
			
			inline Letter::Tuple_ptr Letter::sel(Letter::Tuple_ptr tup)
			{
				pgc::Statement stm_ = stm("sel_id");
				
				if(stm_.empty()) {
					stm_.sql(tupleSelSql(*tup));
				}
				
				stm_.bind(tup->id.value());
				stm_.exec().throwIfError();
			}
			
			inline std::string  Letter::tupleFillKey(Tuple &tup)
			{
				std::string res(5, '0');
				
				if(tup.comment.fvs() != fields::fvs_notset) {
					res[0] = '1';
				}
				
				if(tup.content.fvs() != fields::fvs_notset) {
					res[1] = '1';
				}
				
				if(tup.creation.fvs() != fields::fvs_notset) {
					res[2] = '1';
				}
				
				if(tup.file.fvs() != fields::fvs_notset) {
					res[3] = '1';
				}
				
				if(tup.lastModified.fvs() != fields::fvs_notset) {
					res[4] = '1';
				}
				
				return res;
			}
			inline std::string  Letter::tupleInsSql(Tuple &tup)
			{
				std::string res;
				std::string vals;
				size_t idx(0);
				char buf[32];
				
				if(tup.comment.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_comment_\"";
					vals += "$";
					vals += utils::_ntoa(idx + 1, buf);
					idx++;
				}
				
				if(tup.content.fvs() != fields::fvs_notset)
				{
					if(idx)
					{
						res += ",";
						vals += ",";
					}
					
					res += "\"_content_\"";
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
			inline std::string  Letter::tupleUpdSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline std::string  Letter::tupleSelSql(Tuple &tup)
			{
				assert(0);
				return "";
			}
			inline void  Letter::tupleInsBind(Tuple &tup, pgc::Statement &stm)
			{
				size_t idx(0);
				
				if(tup.comment.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.comment.value(), idx + 1);
					idx++;
				}
				
				if(tup.content.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.content.value(), idx + 1);
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
				
				if(tup.lastModified.fvs() != fields::fvs_notset)
				{
					stm.bind(tup.lastModified.value(), idx + 1);
					idx++;
				}
			}
			inline void  Letter::tupleUpdBind(Tuple &tup, pgc::Statement &stm)
			{
				assert(0);
			}
		}
	}
}

#endif
