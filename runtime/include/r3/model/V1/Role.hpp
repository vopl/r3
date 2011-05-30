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
				
			public:
			
			public:
				struct Tuple
						: public HasRights::Tuple
				{
					r3::fields::String name;
					r3::relations::Relation2n<User> roles;
				};
				typedef boost::shared_ptr<Tuple> Tuple_ptr;
				
			public:
				template <class Oper> void enumBasesFirst(Oper o);
				template <class Oper> void enumFieldsFromBasesAndSelf(Oper o);
				template <class Oper> void enumRelationsFromBasesAndSelf(Oper o);
				template <class Oper> void enumIndicesFromBasesAndSelf(Oper o);
				
			public:
				~Role();
				V1 *schema();
				
				void ins(Tuple &tup);
				void ins(Tuple_ptr tup);
				
				void upd(Tuple &tup);
				void upd(Tuple_ptr tup);
				
				void del(const boost::int64_t &id);
				void del(Tuple &tup);
				void del(Tuple_ptr tup);
				
				Tuple_ptr sel(const boost::int64_t &id);
				Tuple_ptr sel(Tuple_ptr tup);
				
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
			
			template <class Oper> void Role::enumFieldsFromBasesAndSelf(Oper o)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, (r3::fields::Bool *)NULL, "attrInHasRights");
				//Role
				Role *c_Role = _schema->getCategory<Role>().get();
				o(this, c_Role, (r3::fields::String *)NULL, "name");
			}
			
			template <class Oper> void Role::enumRelationsFromBasesAndSelf(Oper o)
			{
				//HasRights
				HasRights *c_HasRights = _schema->getCategory<HasRights>().get();
				o(this, c_HasRights, _schema->getCategory<Right>().get(), (r3::relations::Relation2n<Right>*)NULL,	"owners",	(r3::relations::Relation2n<HasRights>*)NULL,	"rights",	rs_dst);
				//Role
				Role *c_Role = _schema->getCategory<Role>().get();
				o(this, c_Role, _schema->getCategory<User>().get(), (r3::relations::Relation2n<User>*)NULL,	"roles",	(r3::relations::Relation2n<Role>*)NULL,	"users",	rs_src);
			}
			
			template <class Oper> void Role::enumIndicesFromBasesAndSelf(Oper o)
			{
				//HasRights
				//Role
			}
			
			inline Role::Role(V1 *s)
				: CategoryBase<Role>("Role")
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
