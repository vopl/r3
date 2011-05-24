#ifndef _R3_MODEL_SCHEMA_common2_HPP_
#define _R3_MODEL_SCHEMA_common2_HPP_

#include "r3/schemaBase.hpp"

#include "category_Category2.hpp"

namespace r3 { namespace model 
{
class Schema_common2
: public SchemaBase<Schema_common2>
{

public:
typedef bmpl::vector<
	  Category_Category2
> TVCategoryTypes;

Category_Category2_ptr category_Category2;

public:
Schema_common2(const char *id);
~Schema_common2();

template <class C> boost::shared_ptr<C> getCategory(){return boost::shared_ptr<C>();}
template <> Category_Category2_ptr	getCategory<Category_Category2>(){return category_Category2;}

Category_Category2_ptr	getCategory_Category2();

};
typedef boost::shared_ptr<Schema_common2> Schema_common2_ptr;
}}

#endif
