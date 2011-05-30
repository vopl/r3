// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_Role_hpp_
#define _r3_model_V1_Role_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/V1/HasRights.hpp"

namespace r3
{
	namespace model
	{
	
		class V1;
		typedef boost::shared_ptr<V1> V1_ptr;
		
		namespace s_V1
		{
		
			class Role
				: public CategoryBase<Role>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<HasRights>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					o(this, c_HasRights, (r3::fields::Bool *)NULL, "attrInHasRights");
					//Role
					Role *c_Role = _schema->getCategory<Role>().get();
					o(this, c_Role, (r3::fields::String *)NULL, "name");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					o(this, c_HasRights, _schema->getCategory<Right>().get(), (r3::relations::Relation2n<Right>*)NULL,	"owners",	(r3::relations::Relation2n<HasRights>*)NULL,	"rights",	rs_dst);
					//Role
					Role *c_Role = _schema->getCategory<Role>().get();
					o(this, c_Role, _schema->getCategory<User>().get(), (r3::relations::Relation2n<User>*)NULL,	"roles",	(r3::relations::Relation2n<Role>*)NULL,	"users",	rs_src);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//HasRights
					//Role
				}
				
			public:
				struct Tuple
						: public HasRights::Tuple
				{
					r3::fields::String name;
					r3::relations::Relation2n<User> roles;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				typedef V1 Schema;
				typedef boost::shared_ptr<V1> Schema_ptr;
				typedef boost::weak_ptr<V1> Schema_wtr;
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
