#ifndef _R3_MODEL_CATEGORY_Category1_HPP_
#define _R3_MODEL_CATEGORY_Category1_HPP_

#include "r3/categoryBase.hpp"

namespace r3 {
	namespace model
	{
		class Schema_common;
		typedef boost::shared_ptr<Schema_common> Schema_common_ptr;
		
		//deriveds
		class Category_HasRights;
		typedef boost::shared_ptr<Category_HasRights> Category_HasRights_ptr;
		
		class Category_Category1
			: public CategoryBase<Category_Category1>
		{
		
		public:
			typedef bmpl::vector <
			> TVBases;
			
			typedef bmpl::vector <
			Category_HasRights
			> TVDeriveds;
			
			
		public:
			typedef Schema_common Schema;
			typedef boost::shared_ptr<Schema_common> Schema_ptr;
			typedef boost::weak_ptr<Schema_common> Schema_wtr;
			Schema *_schema;
			
		public:
			Category_Category1(Schema *s)
				: CategoryBase<Category_Category1>("Category1")
				, _schema(s)
			{
			}
			
			~Category_Category1()
			{
			}
			
			Schema *schema()
			{
				return _schema;
			}
			
		};
		typedef boost::shared_ptr<Category_Category1> Category_Category1_ptr;
	}
}

#endif
