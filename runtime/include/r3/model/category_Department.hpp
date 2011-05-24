#ifndef _R3_MODEL_CATEGORY_Department_HPP_
#define _R3_MODEL_CATEGORY_Department_HPP_

#include "r3/categoryBase.hpp"

namespace r3 { namespace model 
{
class Schema_common;
typedef boost::shared_ptr<Schema_common> Schema_common_ptr;

//bases
class Category_Owner;
typedef boost::shared_ptr<Category_Owner> Category_Owner_ptr;

class Category_Department
: public CategoryBase<Category_Department>
{

protected:
typedef bmpl::vector<
	  Category_Owner
> TVBases;

typedef bmpl::vector<
> TVDeriveds;


public:
typedef Schema_common Schema;

public:
Category_Department();
~Category_Department();

Schema_common_ptr getSchema();
};
typedef boost::shared_ptr<Category_Department> Category_Department_ptr;
}}

#endif
