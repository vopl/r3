#ifndef _R3_MODEL_CATEGORY_Right_HPP_
#define _R3_MODEL_CATEGORY_Right_HPP_

#include "r3/categoryBase.hpp"

namespace r3 { namespace model 
{
class Schema_common;
typedef boost::shared_ptr<Schema_common> Schema_common_ptr;

class Category_Right
: public CategoryBase<Category_Right>
{

public:
typedef bmpl::vector<
> TVBases;

typedef bmpl::vector<
> TVDeriveds;


public:
typedef Schema_common Schema;
typedef boost::shared_ptr<Schema_common> Schema_ptr;
typedef boost::weak_ptr<Schema_common> Schema_wtr;
Schema *_schema;

public:
Category_Right(Schema *s)
: CategoryBase<Category_Right>("Right")
, _schema(s)
{
}

~Category_Right()
{
}

Schema *schema()
{
return _schema;
}

};
typedef boost::shared_ptr<Category_Right> Category_Right_ptr;
}}

#endif
