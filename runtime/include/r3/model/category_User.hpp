#ifndef _R3_MODEL_CATEGORY_User_HPP_
#define _R3_MODEL_CATEGORY_User_HPP_

#include "r3/categoryBase.hpp"

namespace r3 { namespace model 
{
class Schema_common;
typedef boost::shared_ptr<Schema_common> Schema_common_ptr;

//bases
class Category_HasRights;
typedef boost::shared_ptr<Category_HasRights> Category_HasRights_ptr;
class Category_Owner;
typedef boost::shared_ptr<Category_Owner> Category_Owner_ptr;

class Category_User
: public CategoryBase<Category_User>
{

public:
typedef bmpl::vector<
	  Category_HasRights
	, Category_Owner
> TVBases;

typedef bmpl::vector<
> TVDeriveds;


public:
typedef Schema_common Schema;

public:
Category_User();
~Category_User();

Schema_common_ptr getSchema();
};
typedef boost::shared_ptr<Category_User> Category_User_ptr;
}}

#endif
