#ifndef _R3_MODEL_CATEGORY_Role_HPP_
#define _R3_MODEL_CATEGORY_Role_HPP_

#include "r3/categoryBase.hpp"

namespace r3 { namespace model 
{
class Schema_common;
typedef boost::shared_ptr<Schema_common> Schema_common_ptr;

//bases
class Category_HasRights;
typedef boost::shared_ptr<Category_HasRights> Category_HasRights_ptr;

class Category_Role
: public CategoryBase<Category_Role>
{

public:
typedef bmpl::vector<
	  Category_HasRights
> TVBases;

typedef bmpl::vector<
> TVDeriveds;


public:
typedef Schema_common Schema;
typedef boost::shared_ptr<Schema_common> Schema_ptr;
typedef boost::weak_ptr<Schema_common> Schema_wtr;
Schema *_schema;

public:
Category_Role(Schema *s)
: CategoryBase<Category_Role>("Role")
, _schema(s)
{
}

~Category_Role()
{
}

Schema *schema()
{
return _schema;
}

};
typedef boost::shared_ptr<Category_Role> Category_Role_ptr;
}}

#endif
