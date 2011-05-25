#ifndef _r3_model_common_Role_hpp_
#define _r3_model_common_Role_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		namespace s_common
		{
		
			//bases
			class HasRights;
			typedef boost::shared_ptr<HasRights> HasRights_ptr;
			
			class Role
				: public CategoryBase<Role>
			{
			
			public:
				static const bool isAbstract = false;
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//HasRights
					o(this, _schema->getCategory<HasRights>().get(), (r3::fields::Bool *)NULL, "attrInHasRights");
					//Role
					o(this, _schema->getCategory<Role>().get(), (r3::fields::String *)NULL, "name");
				}
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Role(Schema *s)
					: CategoryBase<Role>("Role")
					, _schema(s)
				{
				}
				
				~Role()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Role> Role_ptr;
		}
	}
}

#endif
