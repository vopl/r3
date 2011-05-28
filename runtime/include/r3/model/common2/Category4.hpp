#ifndef _r3_model_common2_Category4_hpp_
#define _r3_model_common2_Category4_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class common2;
		typedef boost::shared_ptr<common2> common2_ptr;
		
		namespace s_common2
		{
		
			class Category4
				: public CategoryBase<Category4>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Category4
					Category4 *c_Category4 = _schema->getCategory<Category4>().get();
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Category4
					Category4 *c_Category4 = _schema->getCategory<Category4>().get();
					o(this, c_Category4, _schema->getCategory<Category3>().get(), (r3::relations::Relation2n *)NULL,	"unnamed1",	(r3::relations::Relation2n *)NULL,	"unnamed2",	rs_src);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Category4
					Category4 *c_Category4 = _schema->getCategory<Category4>().get();
				}
				
			public:
				typedef common2 Schema;
				typedef boost::shared_ptr<common2> Schema_ptr;
				typedef boost::weak_ptr<common2> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Category4(Schema *s)
					: CategoryBase<Category4>("Category4")
					, _schema(s)
				{
				}
				
				~Category4()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Category4> Category4_ptr;
		}
	}
}

#endif
