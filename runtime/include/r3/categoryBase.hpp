#ifndef _R3_CATEGORYBASE_HPP_
#define _R3_CATEGORYBASE_HPP_

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
		pgc::Connection con = category()->schema()->con();
		con.once("CREATE TABLE "+db_sname()+"(id int8 PRIMARY KEY)").exec().throwIfError();
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateFields()
	{
		assert(0);
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
