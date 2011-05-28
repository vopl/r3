#ifndef _r3_model_common2_Category2_hpp_
#define _r3_model_common2_Category2_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class common2;
		typedef boost::shared_ptr<common2> common2_ptr;
		
		namespace s_common2
		{
		
			//deriveds
			class Category3;
			typedef boost::shared_ptr<Category3> Category3_ptr;
			
			class Category2
				: public CategoryBase<Category2>
			{
			
			public:
				static const bool isAbstract = true;
				
				struct DomainEnum
				{
					static const size_t amount = 2;
					static const char *values[amount];
				};
				
				struct DomainSet
				{
					static const size_t amount = 3;
					static const char *values[amount];
				};
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Category2
					Category2 *c_Category2 = _schema->getCategory<Category2>().get();
					o(this, c_Category2, (r3::fields::DateTimeInterval *)NULL, "DateTimeInterval");
					o(this, c_Category2, (r3::fields::Image *)NULL, "Image");
					o(this, c_Category2, (r3::fields::Int16 *)NULL, "Int16");
					o(this, c_Category2, (r3::fields::Int32 *)NULL, "Int32");
					o(this, c_Category2, (r3::fields::Int64 *)NULL, "Int64");
					o(this, c_Category2, (r3::fields::Int8 *)NULL, "Int8");
					o(this, c_Category2, (r3::fields::Money *)NULL, "Money");
					o(this, c_Category2, (r3::fields::Real32 *)NULL, "Real32");
					o(this, c_Category2, (r3::fields::Real64 *)NULL, "Real64");
					o(this, c_Category2, (r3::fields::String *)NULL, "String");
					o(this, c_Category2, (r3::fields::Time *)NULL, "Time");
					o(this, c_Category2, (r3::fields::Timestamp *)NULL, "Timestamp");
					o(this, c_Category2, (r3::fields::Video *)NULL, "Video");
					o(this, c_Category2, (r3::fields::Enum<Category2::DomainEnum>*)NULL, "Enum");
					o(this, c_Category2, (r3::fields::Set<Category2::DomainSet>*)NULL, "Set");
					o(this, c_Category2, (r3::fields::Bool *)NULL, "Bool");
					o(this, c_Category2, (r3::fields::Audio *)NULL, "Audio");
					o(this, c_Category2, (r3::fields::Date *)NULL, "Date");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Category2
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Category2
					Category2 *c_Category2 = _schema->getCategory<Category2>().get();
				}
				
			public:
				typedef common2 Schema;
				typedef boost::shared_ptr<common2> Schema_ptr;
				typedef boost::weak_ptr<common2> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Category2(Schema *s)
					: CategoryBase<Category2>("Category2")
					, _schema(s)
				{
				}
				
				~Category2()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Category2> Category2_ptr;
		}
	}
}

#endif
