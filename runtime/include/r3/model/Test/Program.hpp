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
		
			namespace tuples
			{
				struct Program
						: public TupleBase<Program>
				{
					// Program
					r3::fields::String language;
					r3::fields::String repository;
					// ServicePart
					r3::fields::String comment;
					r3::fields::Money cost;
					r3::fields::DateTimeInterval duration;
					r3::fields::Date start;
					r3::fields::Date stop;
					r3::relations::Relation2n<Document> documents;
					r3::relations::Relation2one<Service> service;
					
					static const size_t _fieldsAmount = 7;
					static const size_t _relationsAmount = 2;
					
				};
				typedef boost::shared_ptr<Program> Program_ptr;
				
			}
			
			class Program
				: public CategoryBase<Test, Program, tuples::Program>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Program Tuple;
				typedef tuples::Program_ptr Tuple_ptr;
				
				typedef Test Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Program();
				Test *schema();
				
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
			
			template <class Oper> void Program::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Program
				Program *c_Program = _schema->getCategory<Program>().get();
				o(this, c_Program, &tup.language, "language");
				o(this, c_Program, &tup.repository, "repository");
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, &tup.comment, "comment");
				o(this, c_ServicePart, &tup.cost, "cost");
				o(this, c_ServicePart, &tup.duration, "duration");
				o(this, c_ServicePart, &tup.start, "start");
				o(this, c_ServicePart, &tup.stop, "stop");
			}
			
			template <class Oper> void Program::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//Program
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n<Document>*)&tup.documents,	"documents",	(r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	rs_src);
				o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one<Service>*)&tup.service,	"service",	(r3::relations::Relation2n<ServicePart>*)NULL,	"parts",	rs_dst);
			}
			
			template <class Oper> void Program::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//Program
				//ServicePart
			}
			
			inline Program::Program(Test *s)
				: CategoryBase<Test, Program, tuples::Program>("Program")
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
			
		}
	}
}

#endif
