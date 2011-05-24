#ifndef _R3_MODEL_SCHEMA_common_HPP_
#define _R3_MODEL_SCHEMA_common_HPP_

#include "r3/schemaBase.hpp"

#include "category_Category1.hpp"
#include "category_HasRights.hpp"
#include "category_Owner.hpp"
#include "category_User.hpp"
#include "category_Right.hpp"
#include "category_Role.hpp"
#include "category_Department.hpp"

namespace r3 { namespace model 
{
class Schema_common
: public SchemaBase<Schema_common>
{
	typedef int KKK;

public:
typedef bmpl::vector<
	  Category_Category1
	, Category_HasRights
	, Category_Owner
	, Category_User
	, Category_Right
	, Category_Role
	, Category_Department
> TVCategoryTypes;

Category_Category1_ptr category_Category1;
Category_HasRights_ptr category_HasRights;
Category_Owner_ptr category_Owner;
Category_User_ptr category_User;
Category_Right_ptr category_Right;
Category_Role_ptr category_Role;
Category_Department_ptr category_Department;

public:
Schema_common(const char *id);
~Schema_common();

template <class C> boost::shared_ptr<C> getCategory(){return boost::shared_ptr<C>();}
template <> Category_Category1_ptr	getCategory<Category_Category1>(){return category_Category1;}
template <> Category_HasRights_ptr	getCategory<Category_HasRights>(){return category_HasRights;}
template <> Category_Owner_ptr	getCategory<Category_Owner>(){return category_Owner;}
template <> Category_User_ptr	getCategory<Category_User>(){return category_User;}
template <> Category_Right_ptr	getCategory<Category_Right>(){return category_Right;}
template <> Category_Role_ptr	getCategory<Category_Role>(){return category_Role;}
template <> Category_Department_ptr	getCategory<Category_Department>(){return category_Department;}

Category_Category1_ptr	getCategory_Category1();
Category_HasRights_ptr	getCategory_HasRights();
Category_Owner_ptr	getCategory_Owner();
Category_User_ptr	getCategory_User();
Category_Right_ptr	getCategory_Right();
Category_Role_ptr	getCategory_Role();
Category_Department_ptr	getCategory_Department();

};
typedef boost::shared_ptr<Schema_common> Schema_common_ptr;
}}

#endif
