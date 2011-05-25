#ifndef _r3_model_common_hpp_
#define _r3_model_common_hpp_

#include "r3/schemaBase.hpp"

#include "r3/model/common/Department.hpp"
#include "r3/model/common/Category1.hpp"
#include "r3/model/common/Owner.hpp"
#include "r3/model/common/HasRights.hpp"
#include "r3/model/common/Role.hpp"
#include "r3/model/common/Right.hpp"
#include "r3/model/common/User.hpp"

namespace r3
{
	namespace model
	{
		namespace s_common {}
		class common;
		typedef boost::shared_ptr<common> common_ptr;
		class common
			: public SchemaBase<common>
		{
		
		public:
			s_common::Department_ptr	_Department;
			s_common::Category1_ptr	_Category1;
			s_common::Owner_ptr	_Owner;
			s_common::HasRights_ptr	_HasRights;
			s_common::Role_ptr	_Role;
			s_common::Right_ptr	_Right;
			s_common::User_ptr	_User;
			
		public:
			common(const char *id)
				: SchemaBase<common>(id, "common")
			{
				init();
			}
			~common()
			{}
			
			template <class Oper> void enumCategories(Oper o)
			{
				common *s = (common *)this;
				o(s, _Department);
				o(s, _Category1);
				o(s, _Owner);
				o(s, _HasRights);
				o(s, _Role);
				o(s, _Right);
				o(s, _User);
			}
			
			template <class C> boost::shared_ptr<C> getCategory()
			{
				return boost::shared_ptr<C>();
			}
			
			template <> s_common::Department_ptr	getCategory<s_common::Department>()
			{
				return _Department;
			}
			
			template <> s_common::Category1_ptr	getCategory<s_common::Category1>()
			{
				return _Category1;
			}
			
			template <> s_common::Owner_ptr	getCategory<s_common::Owner>()
			{
				return _Owner;
			}
			
			template <> s_common::HasRights_ptr	getCategory<s_common::HasRights>()
			{
				return _HasRights;
			}
			
			template <> s_common::Role_ptr	getCategory<s_common::Role>()
			{
				return _Role;
			}
			
			template <> s_common::Right_ptr	getCategory<s_common::Right>()
			{
				return _Right;
			}
			
			template <> s_common::User_ptr	getCategory<s_common::User>()
			{
				return _User;
			}
			
			
			s_common::Department_ptr	getDepartment()
			{
				return _Department;
			}
			
			s_common::Category1_ptr	getCategory1()
			{
				return _Category1;
			}
			
			s_common::Owner_ptr	getOwner()
			{
				return _Owner;
			}
			
			s_common::HasRights_ptr	getHasRights()
			{
				return _HasRights;
			}
			
			s_common::Role_ptr	getRole()
			{
				return _Role;
			}
			
			s_common::Right_ptr	getRight()
			{
				return _Right;
			}
			
			s_common::User_ptr	getUser()
			{
				return _User;
			}
			
			
		};
	}
}

#endif
