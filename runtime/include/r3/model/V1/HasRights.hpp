// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_HasRights_hpp_
#define _r3_model_V1_HasRights_hpp_

#include "r3/categoryBase.hpp"

namespace r3
{
	namespace model
	{
	
		class V1;
		typedef boost::shared_ptr<V1> V1_ptr;
		
		namespace s_V1
		{
		
			//deriveds
			class Role;
			typedef boost::shared_ptr<Role> Role_ptr;
			class User;
			typedef boost::shared_ptr<User> User_ptr;
			
			class HasRights
				: public CategoryBase<HasRights>
			{
			
			public:
				static const bool isAbstract = true;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					o(this, c_HasRights, (r3::fields::Bool *)NULL, "attrInHasRights");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					o(this, c_HasRights, _schema->getCategory<Right>().get(), (r3::relations::Relation2n *)NULL,	"owners",	(r3::relations::Relation2n *)NULL,	"rights",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//HasRights
				}
				
			public:
				typedef V1 Schema;
				typedef boost::shared_ptr<V1> Schema_ptr;
				typedef boost::weak_ptr<V1> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				HasRights(Schema *s)
					: CategoryBase<HasRights>("HasRights")
					, _schema(s)
				{
				}
				
				~HasRights()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<HasRights> HasRights_ptr;
		}
	}
}

#endif
