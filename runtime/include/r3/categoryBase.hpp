#ifndef _R3_CATEGORYBASE_HPP_
#define _R3_CATEGORYBASE_HPP_

#include "r3/fields/Field.h"

namespace r3
{
	template <class C>
	class CategoryBase
	{
		typedef C Category;
		Category *category();

		std::string _name;
	public:
		CategoryBase(const char *name);
		~CategoryBase();

		const std::string &name();
		std::string db_name();
		std::string db_sname();


		void dbCreateTable();
		void dbCreateFields();
		void dbCreateIndices();
		void dbCreateForeignFields();
		void dbCreateCrosses();
		void dbCreateForeignConstraints();
		void dbCreateViews();
	};










	//////////////////////////////////////////////////////////////////////////
	template <class C>
	typename CategoryBase<C>::Category *CategoryBase<C>::category()
	{
		return (Category*)this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	CategoryBase<C>::CategoryBase(const char *name)
		: _name(name)
	{
	}

	template <class C>
	CategoryBase<C>::~CategoryBase()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	const std::string &CategoryBase<C>::name()
	{
		return _name;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	std::string CategoryBase<C>::db_name()
	{
		return "\""+_name+"\"";
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	std::string CategoryBase<C>::db_sname()
	{
		return category()->schema()->db_name()+"."+db_name();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateTable()
	{
		if(!C::isAbstract)
		{
			pgc::Connection con = category()->schema()->con();
			con.once("CREATE TABLE "+db_sname()+"(id int8 PRIMARY KEY)").exec().throwIfError();
		}
	}
	
	namespace impl
	{
		struct enumOper_createField
		{
			template <typename Category, typename CategoryBaseOrSelf> void operator()(Category *c, CategoryBaseOrSelf *bos, r3::fields::String *stub, const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN "+fname+" VARCHAR").exec().throwIfError();
			}
			template <typename Category, typename CategoryBaseOrSelf> void operator()(Category *c, CategoryBaseOrSelf *bos, r3::fields::Enum *stub, const char *fname)
			{
				assert(!"тип енума?");
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN "+fname+" INT4").exec().throwIfError();
			}
			template <typename Category, typename CategoryBaseOrSelf> void operator()(Category *c, CategoryBaseOrSelf *bos, r3::fields::Bool *stub, const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN "+fname+" BOOL").exec().throwIfError();
			}
			template <typename Category, typename CategoryBaseOrSelf> void operator()(Category *c, CategoryBaseOrSelf *bos, void *stub, const char *fname)
			{
				assert(!"добить поля");
			}
		};
	}
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateFields()
	{
		if(!C::isAbstract)
		{
			//перечислить все базовые и себя, собрать все поля и добавить их к таблице
			((C*)this)->enumFieldsFromBasesAndSelf(impl::enumOper_createField());
		}
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateIndices()
	{
		assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateForeignFields()
	{
		assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateCrosses()
	{
		assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateForeignConstraints()
	{
		assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateViews()
	{
		assert(0);
	}

}

#endif
