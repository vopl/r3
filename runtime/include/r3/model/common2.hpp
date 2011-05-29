// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_common2_hpp_
#define _r3_model_common2_hpp_

#include "r3/schemaBase.hpp"

namespace r3
{
	namespace model
	{
		namespace s_common2
		{
			class Category4;
			typedef boost::shared_ptr<Category4> Category4_ptr;
			
			class Category3;
			typedef boost::shared_ptr<Category3> Category3_ptr;
			
			class Category2;
			typedef boost::shared_ptr<Category2> Category2_ptr;
			
		}
		
		class common2;
		typedef boost::shared_ptr<common2> common2_ptr;
		
		class common2
			: public SchemaBase<common2>
		{
		
		public:
			s_common2::Category4_ptr	_Category4;
			s_common2::Category3_ptr	_Category3;
			s_common2::Category2_ptr	_Category2;
			
		public:
			common2(const char *id)
				: SchemaBase<common2>(id, "common2")
			{
				init();
			}
			~common2()
			{}
			
			template <class Oper> void enumCategories(Oper o)
			{
				common2 *s = (common2 *)this;
				o(s, _Category4);
				o(s, _Category3);
				o(s, _Category2);
			}
			
			template <class C> boost::shared_ptr<C> getCategory();
			
			s_common2::Category4_ptr	getCategory4()
			{
				return _Category4;
			}
			
			s_common2::Category3_ptr	getCategory3()
			{
				return _Category3;
			}
			
			s_common2::Category2_ptr	getCategory2()
			{
				return _Category2;
			}
			
			
		};
		template <> s_common2::Category4_ptr	common2::getCategory<s_common2::Category4>()
		{
			return _Category4;
		}
		
		template <> s_common2::Category3_ptr	common2::getCategory<s_common2::Category3>()
		{
			return _Category3;
		}
		
		template <> s_common2::Category2_ptr	common2::getCategory<s_common2::Category2>()
		{
			return _Category2;
		}
		
		
	}
}

#include "r3/model/common2/Category4.hpp"
#include "r3/model/common2/Category3.hpp"
#include "r3/model/common2/Category2.hpp"

#endif
