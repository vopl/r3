#ifndef _R3_MODEL_CATEGORY_User_HPP_
#define _R3_MODEL_CATEGORY_User_HPP_

#include "r3/categoryBase.hpp"

namespace r3 {
	namespace model
	{
		class Schema_common;
		typedef boost::shared_ptr<Schema_common> Schema_common_ptr;
		
		//bases
		class Category_Owner;
		typedef boost::shared_ptr<Category_Owner> Category_Owner_ptr;
		class Category_HasRights;
		typedef boost::shared_ptr<Category_HasRights> Category_HasRights_ptr;
		
		class Category_User
			: public CategoryBase<Category_User>
		{
		
		public:
			typedef bmpl::vector <
			Category_Owner
			, Category_HasRights
			> TVBases;
			
			typedef bmpl::vector <
			> TVDeriveds;
			
			
		public:
			typedef Schema_common Schema;
			typedef boost::shared_ptr<Schema_common> Schema_ptr;
			typedef boost::weak_ptr<Schema_common> Schema_wtr;
			Schema *_schema;
			
		public:
			Category_User(Schema *s)
				: CategoryBase<Category_User>("User")
				, _schema(s)
			{
			}
			
			~Category_User()
			{
			}
			
			Schema *schema()
			{
				return _schema;
			}
			
		};
		typedef boost::shared_ptr<Category_User> Category_User_ptr;
	}
}

#endif
