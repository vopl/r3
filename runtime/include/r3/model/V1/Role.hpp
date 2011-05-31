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
		
			namespace tuples
			{
				struct Role
						: public TupleBase<Role>
				{
					// HasRights
					r3::fields::Bool attrInHasRights;
					r3::relations::Relation2n<Right> owners;
					// Role
					r3::fields::String name;
					r3::relations::Relation2n<User> roles;
					
					static const size_t _fieldsAmount = 2;
					static const size_t _relationsAmount = 2;
					
				};
				typedef boost::shared_ptr<Role> Role_ptr;
				
			}
			
			class Role
				: public CategoryBase<V1, Role, tuples::Role>
			{
			
			public:
				static const bool isAbstract = false;
				
				typedef tuples::Role Tuple;
				typedef tuples::Role_ptr Tuple_ptr;
				
				typedef V1 Schema;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper &o);
				
			public:
				~Role();
				V1 *schema();
				
			protected:
				template <class S> friend class SchemaBase;
				Role(V1 *s);
				
			protected:
				V1 *_schema;
				
			};
			typedef boost::shared_ptr<Role> Role_ptr;
			
			
			//////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////////////////////////////////////////
			template <class Oper> void Role::enumBasesFirst(Oper o)
			{
				o(this, schema()->getCategory<HasRights>().get());
			}
			
			template <class Oper> void Role::enumFieldsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, (r3::fields::Bool *)&tup.attrInHasRights, "attrInHasRights");
				//Role
				Role *c_Role = _schema->getCategory<Role>().get();
				o(this, c_Role, (r3::fields::String *)&tup.name, "name");
			}
			
			template <class Oper> void Role::enumRelationsFromBasesAndSelf(Oper &o, Tuple &tup)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, _schema->getCategory<Right>().get(), (r3::relations::Relation2n<Right>*)&tup.owners,	"owners",	(r3::relations::Relation2n<HasRights>*)NULL,	"rights",	rs_dst);
				//Role
				Role *c_Role = _schema->getCategory<Role>().get();
				o(this, c_Role, _schema->getCategory<User>().get(), (r3::relations::Relation2n<User>*)&tup.roles,	"roles",	(r3::relations::Relation2n<Role>*)NULL,	"users",	rs_src);
			}
			
			template <class Oper> void Role::enumIndicesFromBasesAndSelf(Oper &o)
			{
				//HasRights
				//Role
			}
			
			inline Role::Role(V1 *s)
				: CategoryBase<V1, Role, tuples::Role>("Role")
				, _schema(s)
			{
			}
			
			inline Role::~Role()
			{
			}
			
			inline V1 *Role::schema()
			{
				return _schema;
			}
			
		}
	}
}

#endif
