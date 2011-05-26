#ifndef _r3_model_common2_Category3_hpp_
#define _r3_model_common2_Category3_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/common2/Category2.hpp"

namespace r3
{
	namespace model
	{
	
		class common2;
		typedef boost::shared_ptr<common2> common2_ptr;
		
		namespace s_common2
		{
		
			class Category3
				: public CategoryBase<Category3>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Category2
					Category2 *c_Category2 = _schema->getCategory<Category2>().get();
					o(this, c_Category2, (r3::fields::Enum<Category2::DomainEnum>*)NULL, "Enum");
					o(this, c_Category2, (r3::fields::Set<Category2::DomainSet>*)NULL, "Set");
					o(this, c_Category2, (r3::fields::DateTimeInterval *)NULL, "DateTimeInterval");
					o(this, c_Category2, (r3::fields::Image *)NULL, "Image");
					o(this, c_Category2, (r3::fields::Int16 *)NULL, "Int16");
					o(this, c_Category2, (r3::fields::Int32 *)NULL, "Int32");
					o(this, c_Category2, (r3::fields::Int8 *)NULL, "Int8");
					o(this, c_Category2, (r3::fields::Money *)NULL, "Money");
					o(this, c_Category2, (r3::fields::Real32 *)NULL, "Real32");
					o(this, c_Category2, (r3::fields::Real64 *)NULL, "Real64");
					o(this, c_Category2, (r3::fields::Audio *)NULL, "Audio");
					o(this, c_Category2, (r3::fields::Bool *)NULL, "Bool");
					o(this, c_Category2, (r3::fields::Date *)NULL, "Date");
					o(this, c_Category2, (r3::fields::String *)NULL, "String");
					o(this, c_Category2, (r3::fields::Time *)NULL, "Time");
					o(this, c_Category2, (r3::fields::Timestamp *)NULL, "Timestamp");
					o(this, c_Category2, (r3::fields::Video *)NULL, "Video");
					//Category3
					Category3 *c_Category3 = _schema->getCategory<Category3>().get();
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Category2
					Category2 *c_Category2 = _schema->getCategory<Category2>().get();
					o(this, c_Category2, "Index2", im_tree, (r3::fields::String *)NULL, "String", (r3::fields::Real64 *)NULL, "Real64", (r3::fields::Set<Category2::DomainSet>*)NULL, "Set", (r3::fields::Real32 *)NULL, "Real32");
					o(this, c_Category2, "Index1", im_tree, (r3::fields::Int16 *)NULL, "Int16", (r3::fields::Int8 *)NULL, "Int8", (r3::fields::Int32 *)NULL, "Int32", (r3::fields::Money *)NULL, "Money");
					o(this, c_Category2, "Index", im_tree, (r3::fields::Audio *)NULL, "Audio", (r3::fields::DateTimeInterval *)NULL, "DateTimeInterval");
					//Category3
					Category3 *c_Category3 = _schema->getCategory<Category3>().get();
				}
				
			public:
				typedef common2 Schema;
				typedef boost::shared_ptr<common2> Schema_ptr;
				typedef boost::weak_ptr<common2> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Category3(Schema *s)
					: CategoryBase<Category3>("Category3")
					, _schema(s)
				{
				}
				
				~Category3()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Category3> Category3_ptr;
		}
	}
}

#endif
