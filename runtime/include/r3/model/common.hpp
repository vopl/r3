// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_common_hpp_
#define _r3_model_common_hpp_

#include "r3/schemaBase.hpp"

namespace r3
{
	class Model;
	namespace model
	{
		namespace s_common
		{
			class cat;
			typedef boost::shared_ptr<cat> cat_ptr;
			
		}
		
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		class common
			: public SchemaBase<common>
		{
		
		public:
			s_common::cat_ptr	_cat;
			
		public:
			common(Model *model, const char *id)
				: SchemaBase<common>(model, id, "common")
			{
				init();
			}
			~common()
			{}
			
			template <class Oper> void enumCategories(Oper o)
			{
				common *s = (common *)this;
				o(s, _cat);
			}
			
			template <class C> boost::shared_ptr<C> getCategory();
			
			s_common::cat_ptr	getcat()
			{
				return _cat;
			}
			
			
		};
		template <> s_common::cat_ptr	common::getCategory<s_common::cat>()
		{
			return _cat;
		}
		
		
	}
}

#include "r3/model/common/cat.hpp"

#endif
