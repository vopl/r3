// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_Test_Program_hpp_
#define _r3_model_Test_Program_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/Test/ServicePart.hpp"

namespace r3
{
	namespace model
	{
	
		class Test;
		typedef boost::shared_ptr<Test> Test_ptr;
		
		namespace s_Test
		{
		
			class Program
				: public CategoryBase<Program>
			{
			
			public:
				static const bool isAbstract = false;
				
			public:
			
			public:
				struct Tuple
						: public ServicePart::Tuple
				{
					r3::fields::String language;
					r3::fields::String repository;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Program();
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
				Program(Test *s);
				
			protected:
				Test *_schema;
				
			};
			typedef boost::shared_ptr<Program> Program_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Program::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<ServicePart>().get());
			}
			
			template <class Oper> void Program::enumFieldsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Program
				Program *c_Program = _schema->getCategory<Program>().get();
				o(this, c_Program, (r3::fields::String *)&tup.language, "language");
				o(this, c_Program, (r3::fields::String *)&tup.repository, "repository");
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, (r3::fields::String *)&tup.comment, "comment");
				o(this, c_ServicePart, (r3::fields::Money *)&tup.cost, "cost");
				o(this, c_ServicePart, (r3::fields::DateTimeInterval *)&tup.duration, "duration");
				o(this, c_ServicePart, (r3::fields::Date *)&tup.start, "start");
				o(this, c_ServicePart, (r3::fields::Date *)&tup.stop, "stop");
			}
			
			template <class Oper> void Program::enumRelationsFromBasesAndSelf(Oper o, Tuple &tup)
			{
				//Program
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n<Document>*)&tup.documents,	"documents",	(r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	rs_src);
				o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one<Service>*)&tup.service,	"service",	(r3::relations::Relation2n<ServicePart>*)NULL,	"parts",	rs_dst);
			}
			
			template <class Oper> void Program::enumIndicesFromBasesAndSelf(Oper o)
			{
				//Program
				//ServicePart
			}
			
			inline Program::Program(Test *s)
				: CategoryBase<Program>("Program")
				, _schema(s)
			{
			}
			
			inline Program::~Program()
			{
			}
			
			inline Test *Program::schema()
			{
				return _schema;
			}
			
			inline void Program::ins(Program::Tuple &tup)
			{
				return CategoryBase<Program>::ins(this, tup);
			}
			
			inline void Program::ins(Program::Tuple_ptr tup)
			{
				return ins(*tup);
			}
			
			inline void Program::upd(Program::Tuple &tup)
			{
				return CategoryBase<Program>::upd(this, tup);
			}
			
			inline void Program::upd(Program::Tuple_ptr tup)
			{
				return upd(*tup);
			}
			
			inline void Program::del(const fields::Id &id)
			{
				return CategoryBase<Program>::del(this, id);
			}
			
			inline void Program::del(Program::Tuple &tup)
			{
				return CategoryBase<Program>::del(this, tup);
			}
			
			inline void Program::del(Program::Tuple_ptr tup)
			{
				return del(*tup);
			}
			
			inline Program::Tuple_ptr  Program::sel(const fields::Id &id)
			{
				return CategoryBase<Program>::sel(this, id);
			}
			
			inline Program::Tuple_ptr Program::sel(Program::Tuple_ptr tup)
			{
				return CategoryBase<Program>::sel(this, tup);
			}
			
		}
	}
}

#endif
