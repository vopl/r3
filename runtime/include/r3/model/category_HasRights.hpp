#ifndef _R3_MODEL_CATEGORY_HasRights_HPP_
#define _R3_MODEL_CATEGORY_HasRights_HPP_

#include "r3/categoryBase.hpp"

namespace r3 { namespace model 
{
class Schema_common;
typedef boost::shared_ptr<Schema_common> Schema_common_ptr;

//bases
class Category_Category1;
typedef boost::shared_ptr<Category_Category1> Category_Category1_ptr;

//deriveds
class Category_User;
typedef boost::shared_ptr<Category_User> Category_User_ptr;
class Category_Role;
typedef boost::shared_ptr<Category_Role> Category_Role_ptr;

class Category_HasRights
: public CategoryBase<Category_HasRights>
{

protected:
typedef bmpl::vector<
	  Category_Category1
> TVBases;

typedef bmpl::vector<
	  Category_User
	, Category_Role
> TVDeriveds;


public:
typedef Schema_common Schema;

public:
Category_HasRights();
~Category_HasRights();

Schema_common_ptr getSchema();
};
typedef boost::shared_ptr<Category_HasRights> Category_HasRights_ptr;
}}

#endif
