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
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<ServicePart>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Program
					Program *c_Program = _schema->getCategory<Program>().get();
					o(this, c_Program, (r3::fields::String *)NULL, "Language");
					o(this, c_Program, (r3::fields::String *)NULL, "Repository");
					//ServicePart
					ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
					o(this, c_ServicePart, (r3::fields::String *)NULL, "Comment");
					o(this, c_ServicePart, (r3::fields::Money *)NULL, "Cost");
					o(this, c_ServicePart, (r3::fields::DateTimeInterval *)NULL, "Duration");
					o(this, c_ServicePart, (r3::fields::Date *)NULL, "Start");
					o(this, c_ServicePart, (r3::fields::Date *)NULL, "Stop");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Program
					//ServicePart
					ServicePart *c_ServicePart = _schema->getCategory<ServicePart>().get();
					o(this, c_ServicePart, _schema->getCategory<Document>().get(), (r3::relations::Relation2n *)NULL,	"documents",	(r3::relations::Relation2one *)NULL,	"servicePart",	rs_src);
					o(this, c_ServicePart, _schema->getCategory<Service>().get(), (r3::relations::Relation2one *)NULL,	"service",	(r3::relations::Relation2n *)NULL,	"parts",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Program
					//ServicePart
				}
				
			public:
				typedef Test Schema;
				typedef boost::shared_ptr<Test> Schema_ptr;
				typedef boost::weak_ptr<Test> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Program(Schema *s)
					: CategoryBase<Program>("Program")
					, _schema(s)
				{
				}
				
				~Program()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Program> Program_ptr;
		}
	}
}

#endif
