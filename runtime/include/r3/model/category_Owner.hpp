#ifndef _R3_MODEL_CATEGORY_Owner_HPP_
#define _R3_MODEL_CATEGORY_Owner_HPP_

#include "r3/categoryBase.hpp"

namespace r3 { namespace model 
{
class Schema_common;
typedef boost::shared_ptr<Schema_common> Schema_common_ptr;

//deriveds
class Category_User;
typedef boost::shared_ptr<Category_User> Category_User_ptr;
class Category_Department;
typedef boost::shared_ptr<Category_Department> Category_Department_ptr;

class Category_Owner
: public CategoryBase<Category_Owner>
{

public:
typedef bmpl::vector<
> TVBases;

typedef bmpl::vector<
	  Category_User
	, Category_Department
> TVDeriveds;


public:
typedef Schema_common Schema;
typedef boost::shared_ptr<Schema_common> Schema_ptr;
typedef boost::weak_ptr<Schema_common> Schema_wtr;
Schema *_schema;

public:
Category_Owner(Schema *s)
: CategoryBase<Category_Owner>("Owner")
, _schema(s)
{
}

~Category_Owner()
{
}

Schema *schema()
{
return _schema;
}

};
typedef boost::shared_ptr<Category_Owner> Category_Owner_ptr;
}}

#endif
