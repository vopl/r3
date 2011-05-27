#ifndef _r3_model_common_Role_hpp_
#define _r3_model_common_Role_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/common/Category1.hpp"
#include "r3/model/common/HasRights.hpp"

namespace r3
{
	namespace model
	{
	
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		namespace s_common
		{
		
			class Role
				: public CategoryBase<Role>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Category1
					//HasRights
					//Role
					Role *c_Role = _schema->getCategory<Role>().get();
					o(this, c_Role, (r3::fields::String *)NULL, "name");
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Category1
					//HasRights
					HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
					o(this, c_HasRights, rm_n,	"owners",	rm_n,	"rights",	rs_dst);
					//Role
					Role *c_Role = _schema->getCategory<Role>().get();
					o(this, c_Role, rm_n,	"roles",	rm_n,	"users",	rs_src);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Category1
					//HasRights
					//Role
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
