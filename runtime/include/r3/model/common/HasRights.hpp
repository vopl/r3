#ifndef _r3_model_common_HasRights_hpp_
#define _r3_model_common_HasRights_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/common/Category1.hpp"

namespace r3
{
	namespace model
	{
	
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		namespace s_common
		{
		
			//deriveds
			class User;
			typedef boost::shared_ptr<User> User_ptr;
			class Role;
			typedef boost::shared_ptr<Role> Role_ptr;
			
			class HasRights
				: public CategoryBase<HasRights>
			{
			
			public:
				static const bool isAbstract = true;
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Category1
					Category1 *c_Category1 = _schema->getCategory<Category1>().get();
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Category1
					Category1 *c_Category1 = _schema->getCategory<Category1>().get();
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				}
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				HasRights(Schema *s)
					: CategoryBase<HasRights>("HasRights")
					, _schema(s)
				{
				}
				
				~HasRights()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<HasRights> HasRights_ptr;
		}
	}
}

#endif
