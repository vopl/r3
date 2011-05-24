#ifndef _R3_MODEL_CATEGORY_Category2_HPP_
#define _R3_MODEL_CATEGORY_Category2_HPP_

#include "r3/categoryBase.hpp"

namespace r3 { namespace model 
{
class Schema_common2;
typedef boost::shared_ptr<Schema_common2> Schema_common2_ptr;

class Category_Category2
: public CategoryBase<Category_Category2>
{

public:
typedef bmpl::vector<
> TVBases;

typedef bmpl::vector<
> TVDeriveds;


public:
typedef Schema_common2 Schema;

public:
Category_Category2();
~Category_Category2();

Schema_common2_ptr getSchema();
};
typedef boost::shared_ptr<Category_Category2> Category_Category2_ptr;
}}

#endif
