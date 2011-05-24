#ifndef _R3_MODEL_SCHEMA_common_HPP_
#define _R3_MODEL_SCHEMA_common_HPP_

#include "r3/schemaBase.hpp"

#include "category_Category1.hpp"
#include "category_Owner.hpp"
#include "category_HasRights.hpp"
#include "category_User.hpp"
#include "category_Right.hpp"
#include "category_Role.hpp"
#include "category_Department.hpp"

namespace r3 { namespace model 
{
	class Schema_common
		: public SchemaBase<Schema_common>
	{

	protected:
		typedef bmpl::vector<
			Category_Category1
			, Category_Owner
			, Category_HasRights
			, Category_User
			, Category_Right
			, Category_Role
			, Category_Department
		> TVCategoryTypes;

	public:
		Schema_common(const char *id);
		~Schema_common();

		Category_Category1_ptr	getCategory_Category1();
		Category_Owner_ptr	getCategory_Owner();
		Category_HasRights_ptr	getCategory_HasRights();
		Category_User_ptr	getCategory_User();
		Category_Right_ptr	getCategory_Right();
		Category_Role_ptr	getCategory_Role();
		Category_Department_ptr	getCategory_Department();

	};
	typedef boost::shared_ptr<Schema_common> Schema_common_ptr;
}}

#endif
