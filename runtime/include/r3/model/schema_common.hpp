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
class Schema_common;
typedef boost::shared_ptr<Schema_common> Schema_common_ptr;
class Schema_common
: public SchemaBase<Schema_common>
{

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

Category_Category1_ptr _category_Category1;
Category_HasRights_ptr _category_HasRights;
Category_Owner_ptr _category_Owner;
Category_User_ptr _category_User;
Category_Right_ptr _category_Right;
Category_Role_ptr _category_Role;
Category_Department_ptr _category_Department;

public:
Schema_common(const char *id)
: SchemaBase<Schema_common>(id, "common")
{
init();
}
~Schema_common()
{}

template <class Oper> void enumCategories(Oper o)
{
Schema_common *s = (Schema_common*)this;
o(s, _category_Category1);
o(s, _category_HasRights);
o(s, _category_Owner);
o(s, _category_User);
o(s, _category_Right);
o(s, _category_Role);
o(s, _category_Department);
}

template <class C> boost::shared_ptr<C> getCategory(){return boost::shared_ptr<C>();}
template <> Category_Category1_ptr	getCategory<Category_Category1>(){return _category_Category1;}
template <> Category_HasRights_ptr	getCategory<Category_HasRights>(){return _category_HasRights;}
template <> Category_Owner_ptr	getCategory<Category_Owner>(){return _category_Owner;}
template <> Category_User_ptr	getCategory<Category_User>(){return _category_User;}
template <> Category_Right_ptr	getCategory<Category_Right>(){return _category_Right;}
template <> Category_Role_ptr	getCategory<Category_Role>(){return _category_Role;}
template <> Category_Department_ptr	getCategory<Category_Department>(){return _category_Department;}

Category_Category1_ptr	getCategory_Category1(){return _category_Category1;}
Category_HasRights_ptr	getCategory_HasRights(){return _category_HasRights;}
Category_Owner_ptr	getCategory_Owner(){return _category_Owner;}
Category_User_ptr	getCategory_User(){return _category_User;}
Category_Right_ptr	getCategory_Right(){return _category_Right;}
Category_Role_ptr	getCategory_Role(){return _category_Role;}
Category_Department_ptr	getCategory_Department(){return _category_Department;}

};
}}

#endif
