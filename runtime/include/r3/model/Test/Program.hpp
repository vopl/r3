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
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Program();
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
			
			template <class Oper> void Program::enumFieldsFromBasesAndSelf(Oper o)
			{
				//Program
				Program *c_Program = _schema->getCategory<Program>().get();
				o(this, c_Program, (r3::fields::String *)NULL, "language");
				o(this, c_Program, (r3::fields::String *)NULL, "repository");
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, (r3::fields::String *)NULL, "comment");
				o(this, c_ServicePart, (r3::fields::Money *)NULL, "cost");
				o(this, c_ServicePart, (r3::fields::DateTimeInterval *)NULL, "duration");
				o(this, c_ServicePart, (r3::fields::Date *)NULL, "start");
				o(this, c_ServicePart, (r3::fields::Date *)NULL, "stop");
			}
			
			template <class Oper> void Program::enumRelationsFromBasesAndSelf(Oper o)
			{
				//Program
				//ServicePart
				ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
				o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n<Document>*)NULL,	"documents",	(r3::relations::Relation2one<ServicePart>*)NULL,	"servicePart",	rs_src);
				o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one<Service>*)NULL,	"service",	(r3::relations::Relation2n<ServicePart>*)NULL,	"parts",	rs_dst);
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
			
		}
	}
}

#endif
