// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_Department_hpp_
#define _r3_model_V1_Department_hpp_

#include "r3/categoryBase.hpp"

//bases
#include "r3/model/V1/Owner.hpp"

namespace r3
{
	namespace model
	{
	
		class V1;
		typedef boost::shared_ptr<V1> V1_ptr;
		
		namespace s_V1
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
				typedef V1 Schema;
				typedef boost::shared_ptr<V1> Schema_ptr;
				typedef boost::weak_ptr<V1> Schema_wtr;
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
