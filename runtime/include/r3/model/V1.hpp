// AUTOMATIC GENERATED FILE. DO NOT EDIT MANUALLY!

#ifndef _r3_model_V1_hpp_
#define _r3_model_V1_hpp_

#include "r3/schemaBase.hpp"

namespace r3
{
	class Model;
	namespace model
	{
		namespace s_V1
		{
			class Department;
			typedef boost::shared_ptr<Department> Department_ptr;
			
			class HasRights;
			typedef boost::shared_ptr<HasRights> HasRights_ptr;
			
			class Owner;
			typedef boost::shared_ptr<Owner> Owner_ptr;
			
			class Right;
			typedef boost::shared_ptr<Right> Right_ptr;
			
			class Role;
			typedef boost::shared_ptr<Role> Role_ptr;
			
			class User;
			typedef boost::shared_ptr<User> User_ptr;
			
		}
		
		class V1;
		typedef boost::shared_ptr<V1> V1_ptr;
		
		class V1
			: public SchemaBase<V1>
		{
		
		public:
			s_V1::Department_ptr	_Department;
			s_V1::HasRights_ptr	_HasRights;
			s_V1::Owner_ptr	_Owner;
			s_V1::Right_ptr	_Right;
			s_V1::Role_ptr	_Role;
			s_V1::User_ptr	_User;
			
		public:
			V1(Model *model, const char *id)
				: SchemaBase<V1>(model, id, "V1")
			{
				init();
			}
			~V1()
			{}
			
			template <class Oper> void enumCategories(Oper o)
			{
				V1 *s = (V1 *)this;
				o(s, _Department);
				o(s, _HasRights);
				o(s, _Owner);
				o(s, _Right);
				o(s, _Role);
				o(s, _User);
			}
			
			template <class C> boost::shared_ptr<C> getCategory();
			
			s_V1::Department_ptr	getDepartment()
			{
				return _Department;
			}
			
			s_V1::HasRights_ptr	getHasRights()
			{
				return _HasRights;
			}
			
			s_V1::Owner_ptr	getOwner()
			{
				return _Owner;
			}
			
			s_V1::Right_ptr	getRight()
			{
				return _Right;
			}
			
			s_V1::Role_ptr	getRole()
			{
				return _Role;
			}
			
			s_V1::User_ptr	getUser()
			{
				return _User;
			}
			
			
		};
		template <> s_V1::Department_ptr	V1::getCategory<s_V1::Department>()
		{
			return _Department;
		}
		
		template <> s_V1::HasRights_ptr	V1::getCategory<s_V1::HasRights>()
		{
			return _HasRights;
		}
		
		template <> s_V1::Owner_ptr	V1::getCategory<s_V1::Owner>()
		{
			return _Owner;
		}
		
		template <> s_V1::Right_ptr	V1::getCategory<s_V1::Right>()
		{
			return _Right;
		}
		
		template <> s_V1::Role_ptr	V1::getCategory<s_V1::Role>()
		{
			return _Role;
		}
		
		template <> s_V1::User_ptr	V1::getCategory<s_V1::User>()
		{
			return _User;
		}
		
		
	}
}

#include "r3/model/V1/Department.hpp"
#include "r3/model/V1/HasRights.hpp"
#include "r3/model/V1/Owner.hpp"
#include "r3/model/V1/Right.hpp"
#include "r3/model/V1/Role.hpp"
#include "r3/model/V1/User.hpp"

#endif
