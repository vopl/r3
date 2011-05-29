#ifndef _r3_model_common_Department_hpp_
#define _r3_model_common_Department_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/common/Owner.hpp"

namespace r3
{
	namespace model
	{
	
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		
		namespace s_common
		{
		
			class Department
				: public CategoryBase<Department>
			{
			
			public:
				static const bool isAbstract = false;
				
				template <class Oper> void enumBasesFirst(Oper o)
				{
					o(this, schema()->getCategory<Owner>().get());
				}
				
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o)
				{
					//Department
					Department *c_Department = _schema->getCategory<Department>().get();
					o(this, c_Department, (r3::fields::String *)NULL, "name");
					//Owner
				}
				
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o)
				{
					//Department
					Department *c_Department = _schema->getCategory<Department>().get();
					o(this, c_Department, _schema->getCategory<Owner>().get(), (r3::relations::Relation2one *)NULL,	"parent",	(r3::relations::Relation2n *)NULL,	"childs",	rs_src);
					//Owner
					Owner *c_Owner = _schema->getCategory<Owner>().get();
					o(this, c_Owner, _schema->getCategory<Department>().get(), (r3::relations::Relation2n *)NULL,	"childs",	(r3::relations::Relation2one *)NULL,	"parent",	rs_dst);
				}
				
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o)
				{
					//Department
					//Owner
				}
				
			public:
				typedef common Schema;
				typedef boost::shared_ptr<common> Schema_ptr;
				typedef boost::weak_ptr<common> Schema_wtr;
			protected:
				Schema *_schema;
				
			public:
				Department(Schema *s)
					: CategoryBase<Department>("Department")
					, _schema(s)
				{
				}
				
				~Department()
				{
				}
				
				Schema *schema()
				{
					return _schema;
				}
				
			};
			typedef boost::shared_ptr<Department> Department_ptr;
		}
	}
}

#endif
