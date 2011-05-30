#ifndef _R3_CATEGORYBASE_HPP_
#define _R3_CATEGORYBASE_HPP_

#include "r3/fields/field.h"
#include "r3/relations/relation.hpp"
#include "utils/ntoa.hpp"

namespace r3
{
	template <class C>
	class CategoryBase
	{
	public:
		struct Tuple
		{
			fields::Id id;

			Tuple();
			~Tuple();
		};

	public:
		enum EIndexMethod
		{
			im_tree,
			im_hash,
		};

		enum ERelationSide
		{
			rs_src,
			rs_dst,
		};


	public:

		pgc::Connection con();

		template <class tag>
		pgc::Statement stm(const std::string &key);
		pgc::Statement stm(const std::string &key);

		C *category();
		const std::string &name();
		std::string db_name();
		std::string db_sname();

	protected:
		CategoryBase(const char *name);
		~CategoryBase();

	private:
		struct enumOper_createField;
		struct enumOper_createIndex;
		struct enumOper_createRelation;
		struct enumOper_createInheritance;

	private:
		template <class S> friend class SchemaBase;
		void dbCreateTable();
		void dbCreateFields();
		void dbCreateIndices();
		void dbCreateRelations();
		void dbCreateInheritance();

	private:
		std::string _name;
	};









	//////////////////////////////////////////////////////////////////////////
	template <class C>
	pgc::Connection CategoryBase<C>::con()
	{
		return category()->schema()->con();
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	template <class tag>
	pgc::Statement CategoryBase<C>::stm(const std::string &key)
	{
		return category()->schema()->stm<std::pair<C, tag> >(key);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	pgc::Statement CategoryBase<C>::stm(const std::string &key)
	{
		return category()->schema()->stm<C>(key);
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	typename C *CategoryBase<C>::category()
	{
		return (C*)this;
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	CategoryBase<C>::Tuple::Tuple()
		: id()
	{
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	CategoryBase<C>::Tuple::~Tuple()
	{
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
		con.once("CREATE TABLE "+db_sname()+"(id INT8 PRIMARY KEY DEFAULT nextval('"+category()->schema()->db_name()+".\"idGen\"'::regclass))").exec().throwIfError();
	}

	template <class C>
	struct CategoryBase<C>::enumOper_createField
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

			if(amount <= (size_t)std::numeric_limits<boost::int16_t>::max())
			{
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT2").exec().throwIfError();
			}
			else if(amount <= (size_t)std::numeric_limits<boost::int32_t>::max())
			{
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_\" INT4").exec().throwIfError();
			}
			else if(amount <= (size_t)std::numeric_limits<boost::int64_t>::max())
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
		template <typename Category, typename CategoryBaseOrSelf> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			r3::fields::File *stub,
			const char *fname)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_name\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_ext\" VARCHAR").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_size\" INT4").exec().throwIfError();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_"+fname+"_blob\" OID").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf> void operator()(Category *c, CategoryBaseOrSelf *bos, void *stub, const char *fname)
		{
			//assert(!"добить поля");
			throw std::exception("неизвестный тип поля при добавлении колонки в таблицу");
		}
	};










	//////////////////////////////////////////////////////////////////////////
	template <class C>
	struct CategoryBase<C>::enumOper_createIndex
	{

		template <typename Category, typename CategoryBaseOrSelf>
		std::string sql1(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod)
		{
			std::string res = "CREATE INDEX \"_idx_";
			res += c->name();
			res += "_";
			res += idxName;
			res += "\" ON ";
			res += c->db_sname();
			res += " USING ";

			switch(idxMethod)
			{
			case Category::im_tree:
				res += "btree";
				break;
			case Category::im_hash:
				res += "hash";
				break;
			default:
				assert(!"unknown index method");
				res += "btree";
				break;
			}

			return res;
		}

		std::string sql2(void *stub, const char *fname)
		{
			std::string res = "\"_";
			res += fname;
			res += "_\"";
			return res;
		}

		std::string sql2(r3::fields::Audio *stub, const char *fname)
		{
			std::string res = "\"_";
			res += fname;
			res += "_name\"";
			return res;
		}

		std::string sql2(r3::fields::Image *stub, const char *fname)
		{
			std::string res = "\"_";
			res += fname;
			res += "_name\"";
			return res;
		}

		std::string sql2(r3::fields::Video *stub, const char *fname)
		{
			std::string res = "\"_";
			res += fname;
			res += "_name\"";
			return res;
		}


		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename F0, typename F1, typename F2, typename F3> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod,
			F0 *stub0,
			const char *fname0,
			F1 *stub1,
			const char *fname1,
			F2 *stub2,
			const char *fname2,
			F3 *stub3,
			const char *fname3)
		{
			pgc::Connection con = c->schema()->con();
			con.once(
				sql1(c,bos, idxName, idxMethod)+" ("+
				sql2(stub0, fname0)+", "+
				sql2(stub1, fname1)+", "+
				sql2(stub2, fname2)+", "+
				sql2(stub3, fname3)+")").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename F0, typename F1, typename F2> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod,
			F0 *stub0,
			const char *fname0,
			F1 *stub1,
			const char *fname1,
			F2 *stub2,
			const char *fname2)
		{
			pgc::Connection con = c->schema()->con();
			con.once(
				sql1(c,bos, idxName, idxMethod)+" ("+
				sql2(stub0, fname0)+", "+
				sql2(stub1, fname1)+", "+
				sql2(stub2, fname2)+")").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename F0, typename F1> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod,
			F0 *stub0,
			const char *fname0,
			F1 *stub1,
			const char *fname1)
		{
			pgc::Connection con = c->schema()->con();
			con.once(
				sql1(c,bos, idxName, idxMethod)+" ("+
				sql2(stub0, fname0)+", "+
				sql2(stub1, fname1)+")").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename F0> void operator()(
			Category *c,
			CategoryBaseOrSelf *bos,
			const char *idxName,
			typename Category::EIndexMethod idxMethod,
			F0 *stub0,
			const char *fname0)
		{
			pgc::Connection con = c->schema()->con();
			con.once(
				sql1(c,bos, idxName, idxMethod)+" ("+
				sql2(stub0, fname0)+")").exec().throwIfError();
		}
	};

	template <class C>
	struct CategoryBase<C>::enumOper_createRelation
	{
		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename CategoryAlien>
		void operator()(
			Category *c, CategoryBaseOrSelf *bos, CategoryAlien *ca,
			r3::relations::Relation2one<CategoryAlien> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2one<CategoryBaseOrSelf> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
			if(Category::rs_src == ers)
			{
				pgc::Connection con = c->schema()->con();
				con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_rel_"+nameOwn+"_"+ca->name()+"_id_\" INT8").exec().throwIfError();
			}
			//
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename CategoryAlien>
		void operator()(
			Category *c, CategoryBaseOrSelf *bos, CategoryAlien *ca,
			r3::relations::Relation2one<CategoryAlien> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2n<CategoryBaseOrSelf> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" ADD COLUMN \"_rel_"+nameOwn+"_"+ca->name()+"_id_\" INT8").exec().throwIfError();
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename CategoryAlien>
		void operator()(
			Category *c, CategoryBaseOrSelf *bos, CategoryAlien *ca,
			r3::relations::Relation2n<CategoryAlien> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2one<CategoryBaseOrSelf> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryBaseOrSelf, typename CategoryAlien>
		void operator()(
			Category *c, CategoryBaseOrSelf *bos, CategoryAlien *ca,
			r3::relations::Relation2n<CategoryAlien> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2n<CategoryBaseOrSelf> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
		}

		//////////////////////////////////////////////////////////////////////////
		template <typename Category, typename CategoryAlien>
		void operator()(
			Category *c, Category *bos, CategoryAlien *ca,
			r3::relations::Relation2n<CategoryAlien> *stubOwn,	const char *nameOwn,
			r3::relations::Relation2n<Category> *stubAlien, const char *nameAlien,
			typename Category::ERelationSide ers)
		{
			if(Category::rs_src == ers)
			{
				pgc::Connection con = c->schema()->con();

				std::string tableName = "\""+c->schema()->name()+"_"+c->schema()->id()+"\".\"_refcross_"+nameOwn+"_"+ca->name()+"_"+nameAlien+"_"+c->name()+"_\"";
				con.once(
					"CREATE TABLE "+tableName+"("+
					"\"_rel_"+nameOwn+"_"+ca->name()+"_id_\" INT8,"
					"\"_rel_"+nameAlien+"_"+c->name()+"_id_\" INT8"
					")").exec().throwIfError();
			}
		}
	};


	template <class C>
	struct CategoryBase<C>::enumOper_createInheritance
	{
		template <typename Category, typename CategoryBase>
		void operator()(Category *c, CategoryBase *bc)
		{
			pgc::Connection con = c->schema()->con();
			con.once("ALTER TABLE "+c->db_sname()+" INHERIT "+bc->db_sname()).exec().throwIfError();
		}

	};

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateFields()
	{
		//перечислить все базовые и себя, собрать все поля и добавить их к таблице
		((C*)this)->enumFieldsFromBasesAndSelf(enumOper_createField());
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateIndices()
	{
		//перечислить все базовые и себя, собрать все индексы и добавить их к таблице
		((C*)this)->enumIndicesFromBasesAndSelf(enumOper_createIndex());
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateRelations()
	{
		((C*)this)->enumRelationsFromBasesAndSelf(enumOper_createRelation());
	}

	//////////////////////////////////////////////////////////////////////////
	template <class C>
	void CategoryBase<C>::dbCreateInheritance()
	{
		((C*)this)->enumBasesFirst(enumOper_createInheritance());
	}

}

#endif
