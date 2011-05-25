#ifndef _R3_MODEL_CATEGORY_HasRights_HPP_
#define _R3_MODEL_CATEGORY_HasRights_HPP_

#include "r3/categoryBase.hpp"

namespace r3 {
	namespace model
	{
		class Schema_common;
		typedef boost::shared_ptr<Schema_common> Schema_common_ptr;
		
		//bases
		class Category_Category1;
		typedef boost::shared_ptr<Category_Category1> Category_Category1_ptr;
		
		//deriveds
		class Category_Role;
		typedef boost::shared_ptr<Category_Role> Category_Role_ptr;
		class Category_User;
		typedef boost::shared_ptr<Category_User> Category_User_ptr;
		
		class Category_HasRights
			: public CategoryBase<Category_HasRights>
		{
		
		public:
			typedef bmpl::vector <
			Category_Category1
			> TVBases;
			
			typedef bmpl::vector <
			Category_Role
			, Category_User
			> TVDeriveds;
			
			
		public:
			typedef Schema_common Schema;
			typedef boost::shared_ptr<Schema_common> Schema_ptr;
			typedef boost::weak_ptr<Schema_common> Schema_wtr;
			Schema *_schema;
			
		public:
			Category_HasRights(Schema *s)
				: CategoryBase<Category_HasRights>("HasRights")
				, _schema(s)
			{
			}
			
			~Category_HasRights()
			{
			}
			
			Schema *schema()
			{
				return _schema;
			}
			
		};
		typedef boost::shared_ptr<Category_HasRights> Category_HasRights_ptr;
	}
}

#endif
