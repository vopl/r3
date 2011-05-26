#ifndef _R3_CATEGORYBASE_HPP_
#define _R3_CATEGORYBASE_HPP_

#include "r3/fields/Field.h"
#include "utils/ntoa.hpp"

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


			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Audio *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_name\" VARCHAR").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_ext\" VARCHAR").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_size\" INT4").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Bool *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" BOOL").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Date *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" DATE").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::DateTimeInterval *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INTERVAL").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf, typename Domain> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Enum<Domain> *stub, 
				const char *fname)
			{
				static const size_t amount = r3::fields::Enum<Domain>::amount;
				
				pgc::Connection con = c->schema()->con();

				if(amount <= std::numeric_limits<boost::int16_t>::max())
				{
					con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT2").exec().throwIfError();
				}
				else if(amount <= std::numeric_limits<boost::int32_t>::max())
				{
					con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT4").exec().throwIfError();
				}
				else if(amount <= std::numeric_limits<boost::int64_t>::max())
				{
					con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT8").exec().throwIfError();
				}
				else
				{
					throw("enum domain too long");
				}
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Image *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_name\" VARCHAR").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_ext\" VARCHAR").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_size\" INT4").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_width\" INT4").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_height\" INT4").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Int16 *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT2").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Int32 *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT4").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Int64 *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT8").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Int8 *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT2").exec().throwIfError();
			}


			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Money *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" MONEY").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Real32 *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" FLOAT4").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Real64 *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" FLOAT8").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf, typename Domain> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Set<Domain> *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();

				static const size_t amount = r3::fields::Set<Domain>::amount;
				char buf[64];
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" BIT("+utils::_ntoa(amount, buf)+")").exec().throwIfError();
			}
			
			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::String *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" VARCHAR").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Time *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" TIME WITHOUT TIME ZONE").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Timestamp *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" TIMESTAMP WITHOUT TIME ZONE").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(
				Category *c, 
				CategoryBaseOrSelf *bos, 
				r3::fields::Video *stub, 
				const char *fname)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_name\" VARCHAR").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_ext\" VARCHAR").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_size\" INT4").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_width\" INT4").exec().throwIfError();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_height\" INT4").exec().throwIfError();
			}

			//////////////////////////////////////////////////////////////////////////
			template <typename Category, typename CategoryBaseOrSelf> void operator()(Category *c, CategoryBaseOrSelf *bos, void *stub, const char *fname)
			{
				//assert(!"добить поля");
				throw std::exception("неизвестный тип поля при добавлении колонки в таблицу");
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
		//assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateForeignFields()
	{
		//assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateCrosses()
	{
		//assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateForeignConstraints()
	{
		//assert(0);
	}
	
	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateViews()
	{
		//assert(0);
	}

}

#endif
