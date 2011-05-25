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
		
			class Category2
				: public CategoryBase<Category2>
			{
			
			public:
				static const bool isAbstract = false;
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Category2
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
